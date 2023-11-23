# Template Metaprogramming with C++ 

<a href="https://www.amazon.com/Template-Metaprogramming-everything-templates-metaprogramming/dp/1803243457?utm_source=github&utm_medium=repository&utm_campaign=9781801076012"><img src="https://images-na.ssl-images-amazon.com/images/I/41X9zP2asoL._SX258_BO1,204,203,200_.jpg" alt="Template Metaprogramming with C++ " height="256px" align="right"></a>

This is the code repository for [Template Metaprogramming with C++ ](https://www.amazon.com/Template-Metaprogramming-everything-templates-metaprogramming/dp/1803243457?utm_source=github&utm_medium=repository&utm_campaign=9781801076012), published by Koshkaaa_.

> ***了解C++模板的一切，并释放模板元编程的力量***

## What is this book about?
Templates are a key feature of the C++language, enabling us to reuse source code, write more efficient code, and create universal libraries that can be used in many applications. However, they are often complex and difficult to understand. This book will help you understand and write templates, from the simplest form to the latest C++20 features.

This book covers the following exciting features:
* Understand the syntax for all types of templates
* Discover how specialization and instantiation works
* Get to grips with template argument deduction and forwarding references
* Write variadic templates with ease
* Become familiar with type traits and conditional compilation
* Restrict template arguments in C++20 with constraints and concepts
* Implement patterns such as CRTP, mixins, and tag dispatching

If you feel this book is for you, get your [copy](https://www.amazon.com/dp/1803243457) today!

<a href="https://www.packtpub.com/?utm_source=github&utm_medium=banner&utm_campaign=GitHubBanner"><img src="https://raw.githubusercontent.com/PacktPublishing/GitHub/master/GitHub.png" 
alt="https://www.packtpub.com/" border="5" /></a>

## Errata

* Page 258: The line of code ``return value--;`` must be read as ``return value-1;`` or ``return --value;``

## Instructions and Navigations
All of the code is organized into folders. For example, Chapter02.

The code will look like the following:
```cpp
template <typename T>
struct parser : base_parser<T>
{
    void parse()
    {
        this->init(); // OK
        std::cout << "parse\n";
    }
};
```
## Structure

The source code for the book is organized per chapters. Each chapter has its own subfolder in the `src` folder. These subfolders are called `chapter_01`, `chapter_02`, etc. For most chapters, the code is found in a single source file, `main.cpp`. This file is organized in multiple namespaces, such as `n101`, `n102`, `n103` etc. for the first chapter, `n201`, `n202`, `n203` etc. for the second chapter and so on.

## Supported compilers

All the code provided in the book is cross-platform. You can use any of the major compilers, MSVC, Clang, or GCC to compile the sources.

You can also run snippets of code using compilers available online:

- [Compiler Explorer](https://godbolt.org/)
- [Wandbox](https://wandbox.org/)
- [C++ Insights](https://cppinsights.io/)

## How to build

You must have CMake to build the code.

### Example for creating a Visual Studio solution

Run the following commands to create a solution for Visual Studio 2019:

```bash
mkdir build
cd build
cmake -G "Visual Studio 16 2019" -A x64 ..
```

Run the following commands to create a solution for Visual Studio 2022:

```bash
mkdir build
cd build
cmake -G "Visual Studio 17 2022" -A x64 ..
```

**Following is what you need for this book:**
This book is for beginner-to-intermediate C++ developers who want to learn about template metaprogramming as well as advanced C++ developers looking to get up to speed with the new C++20 features related to templates and the the various idioms and patterns. Basic C++ coding experience is necessary to get started with this book.

We also provide a PDF file that has color images of the screenshots/diagrams used in this book. [Click here to download it](https://packt.link/Un8j5).

### Related products
* C++20 STL Cookbook [[Packt]](https://www.packtpub.com/product/c-20-stl-cookbook/9781803248714?utm_source=github&utm_medium=repository&utm_campaign=9781803248714) [[Amazon]](https://www.amazon.com/dp/1803248718)

* CMake Best Practices [[Packt]](https://www.packtpub.com/product/cmake-best-practices/9781803239729?utm_source=github&utm_medium=repository&utm_campaign=9781803239729) [[Amazon]](https://www.amazon.com/dp/1803239727)
