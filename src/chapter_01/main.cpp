#include <iostream>

namespace n101
{
   int max(int const a, int const b)
   {
      return a > b ? a : b;
   }

   double max(double const a, double const b)
   {
      return a > b ? a : b;
   }

   using swap_fn = void(*)(void*, int const, int const);    // 接受两个int参数并返回void的函数的类型别名
   using compare_fn = bool(*)(void*, int const, int const); // 接受两个int参数并返回bool的函数类型别名

   /**
    * @brief 将数组按照比较函数指定的顺序进行分区，并返回分区的边界点
    *
    * @param arr 待分区的数组
    * @param low 分区的起始下标
    * @param high 分区的结束下标
    * @param fcomp 比较函数指针，用于指定元素之间的比较顺序
    * @param fswap 交换函数指针，用于交换数组元素的位置
    * @return int 分区的边界点
    */
   int partition(void* arr, int const low, int const high,
      compare_fn fcomp, swap_fn fswap)
   {
      int i = low - 1;

      for (int j = low; j <= high - 1; j++)
      {
         if (fcomp(arr, j, high))
         {
            i++;
            fswap(arr, i, j);
         }
      }

      fswap(arr, i + 1, high);

      return i + 1;
   }

   void quicksort(void* arr, int const low, int const high,
      compare_fn fcomp, swap_fn fswap)
   {
      if (low < high)
      {
         int const pi = partition(arr, low, high, fcomp, fswap);
         quicksort(arr, low, pi - 1, fcomp, fswap);
         quicksort(arr, pi + 1, high, fcomp, fswap);
      }
   }

   // 为了实现快排函数, 需要为传递给函数的每种类型的数组提供比较和交换函数的实现.
   void swap_int(void* arr, int const i, int const j)
   {
      int* iarr = (int*)arr;
      int t = iarr[i];
      iarr[i] = iarr[j];
      iarr[j] = t;
   }

   bool less_int(void* arr, int const i, int const j)
   {
      int* iarr = (int*)arr;
      return iarr[i] <= iarr[j];
   }

   // 定义一个int类型的vector,
   // 但其他类型的 vector 怎么办, 总不可能都写一遍吧
   // 这个时候便体现了 模板 的重要性了.
   struct int_vector
   {
      int_vector();

      size_t size() const;
      size_t capacity() const;
      bool empty() const;

      void clear();
      void resize(size_t const size);

      void push_back(int value);
      void pop_back();

      int at(size_t const index) const;
      int operator[](size_t const index) const;

   private:
      int* data_;
      size_t size_;
      size_t capacity_;
   };

   // 常量表达式, 需要应对不同的编码
   constexpr char NewLine = '\n';
   constexpr wchar_t NewLineW = L'\n';
   constexpr char8_t NewLineU8 = u8'\n';
   constexpr char16_t NewLineU16 = u'\n';
   constexpr char32_t NewLineU32 = U'\n';
}

namespace n102
{
   template <typename T>
   T max(T const a, T const b)
   {
      return a > b ? a : b;
   }

   struct foo {};

   template <typename T>
   void swap(T* a, T* b)
   {
      T t = *a;
      *a = *b;
      *b = t;
   }

   template <typename T>
   int partition(T arr[], int const low, int const high)
   {
      T pivot = arr[high];
      int i = (low - 1);

      for (int j = low; j <= high - 1; j++)
      {
         if (arr[j] < pivot)
         {
            i++;
            swap(&arr[i], &arr[j]);
         }
      }

      swap(&arr[i + 1], &arr[high]);

      return i + 1;
   }

   template <typename T>
   void quicksort(T arr[], int const low, int const high)
   {
      if (low < high)
      {
         int const pi = partition(arr, low, high);
         quicksort(arr, low, pi - 1);
         quicksort(arr, pi + 1, high);
      }
   }

   template <typename T>
   struct Vector
   {
   public:
      Vector();

      size_t size() const;
      size_t capacity() const;
      bool empty() const;

      void clear();
      void resize(size_t const size);

      void push_back(T value);
      void pop_back();

      T at(size_t const index) const;
      T operator[](size_t const index) const;
   private:
      T* data_;
      size_t size_;
      size_t capacity_;
   };

   template<typename T>
   constexpr T NewLine = T('\n');
}

int main()
{
   // 无论模板表示函数、类还是变量，声明和使用模板的语法都是相同的。
   {
      using namespace n101;

      int arr[] = { 13, 1, 8, 3, 5, 2, 1 };
      int n = sizeof(arr) / sizeof(arr[0]);
      quicksort(arr, 0, n - 1, less_int, swap_int);
      for (auto i : arr)
         std::cout << i << " ";
      std::cout << std::endl;
   }

   {
      using namespace n102;

      max(1, 2);        // OK, compares ints
      max(1.0, 2.0);    // OK, compares doubles

      //foo f1, f2;
      //max(f1, f2);      // Error, operator> not overloaded for foo

      max<int>(1, 2);
      max<double>(1.0, 2.0);
      //max<foo>(f1, f2);
   }

   {
      using namespace n102;

      int arr[] = { 13, 1, 8, 3, 5, 2, 1 };
      int n = sizeof(arr) / sizeof(arr[0]);
      quicksort(arr, 0, n - 1);
   }

   {
      using namespace n102;

      std::wstring test = L"demo";
      test += NewLine<wchar_t>;
      std::wcout << test ;// << n101::NewLineW;
   }

   {
      using namespace n102;

      // 目前仅声明了定义
      // Vector<int> v; // error
      // v.push_back(1); // error
      // v.push_back(2);
      // std::cout << v.at(1); // error
   }
}