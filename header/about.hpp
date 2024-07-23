/**
 * @file about.hpp
 * @author JakeTheRealOne
 * @brief Header file for About class
 * @version 0.1
 * @date 23-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


# ifndef ABOUT_HPP
# define ABOUT_HPP


// #### Std inclusions: ####
# include <string>
using namespace std;

// #### Qt inclusions: ####
# include <QWidget>
# include <QLabel>
# include <QPushButton>
# include <QLayout>
# include <QVBoxLayout>


const extern string APPNAME, APPVERSION;


/**
 * @brief About page of the application
 * 
 */
class About : public QWidget 
{
public:
  // #### Constructors: ####

  /**
  * @brief Construct a new About object
  * 
  */
  About();

  // #### Destructor: ####

  /**
  * @brief Destroy the About object
  * 
  */
  ~About() = default;

private:
  // #### Attributes: ####

  QLabel appName = QLabel(QString::fromStdString(APPNAME)), appVersion = QLabel(QString::fromStdString(APPVERSION));
  QPushButton toWebsite = QPushButton("Github page"), closeButton = QPushButton("X");
  QHBoxLayout mainLayout;

// #### Auxiliary methods: ####

  /**
   * @brief Build the children of the About page
   * 
   */
  void buildChildren();

  /**
   * @brief Build the layouts of the About page
   * 
   */
  void buildLayouts();

  /**
   * @brief Build the style of the About page
   * 
   */
  void buildStyle();
};


# endif