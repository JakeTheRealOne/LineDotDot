/**
 * @file settingsMenu.hpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Header file for the SettingsMenu widget
 * @version 0.1
 * @date 25-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


# ifndef SETTINGS_MENU_HPP
# define SETTINGS_MENU_HPP


// #### Qt inclusions: ####
# include <QWidget>
# include <QVBoxLayout>
# include <QHBoxLayout>
# include <QPushButton>
# include <QResizeEvent>
# include <QLabel>
# include <QCheckBox>


/**
 * @brief The menu that pops up when the settings button is pushed
 * 
 */
class SettingsMenu : public QWidget
{
public:
  // #### Constructors: ####

  /**
   * @brief Construct a new Settings Menu object
   * 
   */
  SettingsMenu();

  ~SettingsMenu() = default;

private:
  // #### Attributes: ####
  QWidget darkBox, mainBox;
  QVBoxLayout mainLayout;
  QHBoxLayout darkLayout, voidLayout;
  QPushButton aboutButton = QPushButton("About LineDotDot"), languageButton = QPushButton("Language");
  QLabel darkLabel = QLabel("Dark mode");
  QCheckBox darkCheckBox;

  // #### Auxiliary methods: ####

  void buildStyle();

  void buildButtons();

  void buildLayouts();

protected:
  /**
   * @brief Remove the possibility to resize the widget
   * 
   * @param event 
   */
  void resizeEvent(QResizeEvent* event);
};


# endif