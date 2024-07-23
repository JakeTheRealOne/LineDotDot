/**
 * @file gui.hpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Source file of the GUI class
 * @version 0.1
 * @date 2024-07-19
 *
 * @copyright Copyright (c) 2024
 *
 */


# ifndef GUI_HPP
# define GUI_HPP


// #### Qt inclusions: ####
# include <QApplication>
# include <QBoxLayout>
# include <QHBoxLayout>
# include <QLabel>
# include <QMainWindow>
# include <QPropertyAnimation>
# include <QPushButton>
# include <QScrollBar>
# include <QSize>
# include <QString>
# include <QTextEdit>
# include <QVBoxLayout>
# include <QWidget>
# include <QMenu>
# include <QAction>
# include <QThread>
# include <QPainter>
# include <QPainterPath>

// #### Std inclusions: ####
# include <iostream>
# include <string>
using namespace std;

// #### Intern inclusions: ####
# include "../header/decoder.hpp"
# include "../header/encoder.hpp"
# include "../header/about.hpp"

/**
 * @brief Interface of the application
 * 
 */
class GUI : public QWidget
{
public:
  // #### Constructors: ####

  /**
   * @brief Construct a new GUI object
   * 
   */
  GUI();

  // #### Destructors: ####

  /**
   * @brief Destroy the GUI object
   * 
   */
  // ~GUI(); Removing because it leads to a Stack smashing

  // #### Open methods: ####

  /**
   * @brief Send a notification to the user (appear on the top bar)
   * 
   * @param content The content (max 64 characters)
   * @param type The level (0 = neutral, 1 = error, 2 = warning, 3 = success, 4 = information, 5 = question)
   * @param duration The duration (might be cut if another notification appear right after it)
   */
  void notify(const QString& content, const char type, const int duration);

private:
  // #### Attributes: ####

  QWidget mainWindow, bottomBar, topBar, translateTextBox, switchBox, notificationBox;
  QVBoxLayout tmpLayout, mainLayout, translateTextLayout; //tmpLayout = QVBoxLayout(this);
  QHBoxLayout bottomLayout, topLayout, sbLayout, notificationLayout;
  QPushButton closeButton = QPushButton(""),
              encyclopediaButton = QPushButton(""),
              radioButton = QPushButton("󰜟"),
              settingsButton = QPushButton(""),
              textButton = QPushButton(""),
              fileButton = QPushButton("󰈙"),
              materialButton = QPushButton("󰳽"),
              flashButton = QPushButton(""),
              swapButton = QPushButton("󰯎");
  QTextEdit inputTextBox, outputTextBox;
  QLabel warningLabel =
    QLabel("File mode is recommended for processing large amounts of data."),
    notificationIcon,
    notificationText;
  QMenu textBoxMenu, settingsMenu;
  QThread* notificationThread;
  About aboutPage;


  bool inputIsMorse = false, notification = false;
  char currentMode =
    -1; //< 0: text mode, 1: file mode, 2: material mode, 3: flash mode

  // #### Auxiliary methods: ####

  /**
   * @brief Build the top and bottom bars
   * 
   */
  void buildBars();

  /**
   * @brief Build the layouts of the GUI
   * 
   */
  void buildLayouts();

  /**
   * @brief Build the buttons of the GUI
   * 
   */
  void buildButtons();

  /**
   * @brief Build the style of the GUI
   * 
   */
  void buildStyle();


  /**
   * @brief Build the box for text translation
   * 
   */
  void buildTranslateBox();

  /**
   * @brief Build the animations of the GUI
   * 
   */
  void buildAnimations();

  /**
   * @brief Build the menus of the GUI
   * 
   */
  void buildMenus();

  /**
   * @brief Build the notification of the GUI
   * 
   */
  void buildNotification();

  /**
   * @brief Run (handmade) the animation for notifications
   * 
   */
  void notificationPopup ();

  /**
   * @brief Helper for the public method notify
   * 
   * @param content The content (max 64 characters)
   * @param type The level (0 = neutral, 1 = error, 2 = warning, 3 = success, 4 = information, 5 = question)
   * @param duration The duration (might be cut if another notification appear right after it)
   */
  void notifyHelper(const QString& content, const char type, const int duration);

  // #### Button actions: ####

  /**
   * @brief Action executed when the inputBox content changes
   * 
   */
  void inputChanged();

  /**
   * @brief Action executed when the itextButton is clicked
   * 
   */
  void switchToTextMode();

  /**
   * @brief Action executed when the fileButton is clicked
   * 
   */
  void switchToFileMode();

  /**
   * @brief Action executed when the materialButton
   * 
   */
  void switchToMaterialMode();

  /**
   * @brief Action executed when the flashButton is clicked
   * 
   */
  void switchToFlashMode();

  /**
   * @brief Action executed when the swapButton is clicked
   * 
   */
  void swapTextBoxes();

  /**
   * @brief Open/Close the knowledge book
   * 
   */
  void toggleKnowledgeBook();

  /**
   * @brief Open/Close the radio
   * 
   */
   void toggleRadio();

   /**
    * @brief Open/Close the settings menu
    * 
    */
    void toggleSettings();

protected:

  /**
  * @brief Apply rounded corners to the 
  * 
  */
  void paintEvent(QPaintEvent *);
};


# endif