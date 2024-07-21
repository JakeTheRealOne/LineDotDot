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

// #### Std inclusions: ####
# include <iostream>
# include <string>
using namespace std;

// #### Intern inclusions: ####
# include "../header/gui.hpp"
# include "../header/convert.hpp"


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
  ~GUI() = default;

private:
  // #### Attributes: ####

  QWidget bottomBar, topBar, translateBox, switchBox;
  QVBoxLayout mainLayout, translateLayout;
  QHBoxLayout bottomLayout, topLayout, sbLayout;
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
    QLabel("File mode is recommended for processing large amounts of data.");
  bool inputIsMorse = false;
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


  // #### Button actions:

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
};


# endif