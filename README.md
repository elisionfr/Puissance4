 # STUFF - Sparkling Thundering Unanimously Fabulous Framework
The Big Picture here is to build several programs around a similar homemade framework called STUFF.
That framework is based on SFML, but everything else will be homemade:
- GUI
- Network abilities (uses SFML network classes)
- Launcher
- Image processing
- Sound Processing
- Application overhaul architecture
- Patterns
- etc...

 # What will this look like ?
Each program will be compiled seperately.
A Launcher program will allow to choose which program to launch, even if each program will be able to be launched seperately.
Each program will be placed in a category.

 # What architecture will be used ?
The framework will be compiled seperately and linked synamically to SFML.
Each program will then link to the framework statically or dynamically.

 # List of programs :
- Launcher : Can launch other programs
- 4Chain : A game copyinh the Connect4 game
- StuffGUI : A program to show off the homemade GUI system

# Special Functionalities
- FloatingTabs : Make window tabs float as icons in circles and magnet to the windows sides

Here is an example of what I would like to do for STUFF :
```cpp
//A Typical Main function
main()
{
    STUFF::CreateWindow<cMainWindow>("ID", arg1, arg2);
    STUFF::GetWindow<cMainWindow>("ID");
    STUFF::DestroyWindow("ID");
        
    STUFF::Run(); //Runs App => STUFF::WM::Draw && STUFF::WM::ProcessEvent
}
    
//A Typical Window
//MainWindow.h
class cMainWindow : STUFF::cWindow
{
private:
    cMainWindow(Arg1 iArg1, Arg2 iArg2);

private:
    virtual OnEvent();
    virtual OnDraw();

private:
    virtual SFML::Window* CreateUnderlyingWindow(); //Optional
    SFML::Window* GetUnderlyingWindow();
    virtual STUFF::cWidget* CreateWidget(); //Optional : but highly recommended, otherwise the window will be empty, but you also could draw directly to the window without widget
};

//a Typical Widget Construction
NewWidget<MyWidget>()
.Option1(10)
.Option2(20)
.Content
(
    NewWidget<SubWidget>
    .Option1(10)
    .Option2(20)
)
.Content //MultiSlot Content
(
    NewWidget<SubWidget>
    .Option1(10)
    .Option2(20),

    NewWidget<SubWidget>
    .Option1(10)
    .Option2(20)
)
.MySlot
(
    NewWidget<SubWidget>
    .Option1(10)
    .Option2(20)
)
.MyMultiSlot
(
    NewWidget<SubWidget>
    .Option1(10)
    .Option2(20),

    NewWidget<SubWidget>
    .Option1(10)
    .Option2(20)
);

//a Typical Widget Option declaration
DECLARE_OPTION(Type1, Name1)
/* template<class tReturnType>
class Name1
{
    virtual ~Name1() {};

    tReturnType& Name1(const Type1& iValue) { Option1 = iValue; return *this; };

private:
    Type1 Value;
}; */

DECLARE_OPTION_GROUP(GroupName, Options...)
/* template<class tReturnType>
class GroupName : public TOptionGroup<Options>
{
    virtual ~GroupName() {};
}; */

class cWidgetClassName : cSomeOtherWidget
{   
    //Options declaration could take place here or outside of the class, it doesn't matter
    WIDGET_OPTIONS(
        Name1, // a single option
        GroupName, // a group of options
        cOtherWidget::OptionName, // an option from another widget
        cOtherWidget::GroupName, // an group of options from another widget
    )
        
    WIDGET_OPTIONS(...)
    /* class cOptions : TWidgetOptions<cOptions>
    {
    }; */

    void Construct(const cOptions&)
    {
    }
};
```
