# Solar
2D OpenGL Game Framework.

---

### Disclaimer

**Solar** framework is free and open-source under the [MIT license](LICENSE).
**Solar** only supports 64-bit Windows applications (for now).

**Solar** is an education project for learning purposes, feel free to use it in commercial projects, just keep in mind that support is minimal.

---

### Requirements:

- Visual Studio 2019 (Untested on older versions of Visual Studio)
- or Visual Studio Code.
- Visual C++ compiler.

---

### Getting Started:

Clone Solar repository to your local system using `git clone https://github.com/ThaiDuongVu/Solar.git`

Open Solar solution with Visual Studio.

You can see 2 projects in Solar solution: Solar and Lunar.

![projects](images/projects.png)

 **Solar** is the framework itself.

 **Lunar** is a test project, containing examples with commented code and showcasing the capabilities of Solar framework.

**Solar** only supports 64-bit projects and so **Lunar** is an only 64-bit application.

Hit `Ctrl+Shift+B` to build solution.

![build](images/build.png)

Hit `F5` to run **Lunar**.

![run](images/run.png)

---

### Creating New Projects

1. Right click on solution and choose **Add** **->** **New Project...**

![new project](images/new_project.png)

2. Choose C++ Empty Project.

![c++ empty](images/c++_empty.png)

3. Name your project and hit **Create**.

![name project](images/name_project.png)

4. Select your newly created project and go to **View** **->** **Other Windows** **->** **Property Manager**.

![property manager](images/property_manager.png)

5. Right click on your project and choose **Add existing property sheet....**

![add sheet](images/add_sheet.png)

6. Select **Solar Project.props** from solution directory.

![props](images/props.png)

And *voila* you have a project configured to work with Solar framework, time to jump into the code.

7. Verify everything is working by creating a main.cpp in new project and running this code:

        #include <Solar.h>

        int main()
        {
            Solar::App *app = new Solar::App();
            app->Run();
        }

8. You should see the following window by default:

![default window](images/default_window.png)
