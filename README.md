<p><img src="images/logo.png" width=200></p>

2D OpenGL Game Framework.

---

### Table of Contents
- [About](#about)
- [Features](#features)
- [Tutorials and Documentation](#tutorials-and-documentation)
- [Contributing](#contributing)
- [Requirements](#requirements)
- [Getting Started](#getting-started)
- [Creating New Projects](#creating-new-projects)

---

### About

**Solar** framework is free and open-source under the [MIT license](LICENSE).

**Solar** supports 64-bit Windows applications (for now).

**Solar** is an education project for learning purposes, feel free to use it in personal and commercial projects, just keep in mind that support is minimal.

🚨 Heads up, **Solar** is evolving... Check out [**sidekick**](https://github.com/ThaiDuongVu/sidekick), **Solar**'s successor, written entirely in Rust.

---

### Features

#### Current features:
- Window Management.
- Cursor Management.
- Custom Math Library.
- Mouse Input Handling.
- Keyboard Input Handling.
- Gamepad Input Handling.
- Basic Shapes Rendering (Line, Triangle, Square).
- Text Rendering.

#### Planned features:
- Sprite Rendering.
- Audio Playing.
- 2D Physics.
- 2D Lighting & Shadow.

---

### Tutorials and Documentation

You can refer to the [wiki page](https://github.com/ThaiDuongVu/Solar/wiki) (whenever it's live 🤷‍♂️) for an in-depth guide to Solar.

Check out [PongSolar](https://github.com/ThaiDuongVu/PongSolar), a Pong game made with Solar for some sample code.

---

### Contributing

**Solar** is completely open to community contribution. Any effort to help expand the scope and capability of the framework is greatly appreciated 🤗.

---

### Requirements

- Visual Studio 2019 (Untested on older versions of Visual Studio) or Visual Studio Code.
- Microsoft Visual C++ compiler.

---

### Getting Started

Clone Solar repository to your local system using `git clone --recursive https://github.com/ThaiDuongVu/Solar.git`

Open Solar solution `Solar.sln` with Visual Studio.

You can see 2 projects in Solar solution: **Solar** and **Lunar**.

<!-- ![projects](images/projects.png) -->
<img src="images/projects.png" width=200>

 **Solar** is the framework itself.

 **Lunar** is a sample project, containing examples with commented code and to showcase the capabilities of Solar framework. **Lunar** can be safely deleted from the solution.

**Solar** only supports 64-bit projects therefore **Lunar** is an only 64-bit application.

Hit `Ctrl+Shift+B` to build solution.

<!-- ![build](images/build.png) -->
<img src="images/build.png" width=450>

Hit `F5` to run **Lunar**.

<!-- ![run](images/run.png) -->
<img src="images/run.png" width=200>

---

### Creating New Projects

1. Right click on solution and choose **Add** **->** **New Project...**

<!-- ![new project](images/new_project.png) -->
<img src="images/new_project.png" width=650>

2. Choose C++ Empty Project.

<!-- ![c++ empty](images/c++_empty.png) -->
<img src="images/c++_empty.png" width=450>

3. Name your project and hit **Create**.

<!-- ![name project](images/name_project.png) -->
<img src="images/name_project.png" width=550>

4. Select your newly created project and go to **View** **->** **Other Windows** **->** **Property Manager**.

<!-- ![property manager](images/property_manager.png) -->
<img src="images/property_manager.png" width=650>

5. Right click on your project and choose **Add existing property sheet....**

<!-- ![add sheet](images/add_sheet.png) -->
<img src="images/add_sheet.png" width=350>

6. Select **SolarSolutionProject.props** from solution directory.

<!-- ![props](images/props.png) -->
<img src="images/props.png" width=250>

7. Right click on newly created project and set it as startup project.

<!-- ![startup](images/startup.png) -->
<img src="images/startup.png" width=350>

And *voila*, you have created a project configured to work with Solar framework, time to jump into the code.

8. Verify everything is working by creating a `main.cpp` in the new project and running this code:

```cpp
        #include <solar.h>
        using namespace Solar;

        int main()
        {
            App *app = new App();
            app->Run();
        }
```

9. You should see the following window by default:

<!-- ![default window](images/default_window.png) -->
<img src="images/default_window.png" width=450>
