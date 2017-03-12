#ifndef QTGAMEZEROMAINDIALOG_H
#define QTGAMEZEROMAINDIALOG_H

#include <set>
#include <memory>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qthideandshowdialog.h"
#pragma GCC diagnostic pop

struct QPixmap;
struct QTimer;

namespace Ui {
  class QtZeroMainDialog;
}


namespace ribi {

class QtZeroMainDialog : public QtHideAndShowDialog
{
  Q_OBJECT //!OCLINT

public:

  explicit QtZeroMainDialog(QWidget *parent = 0);
  QtZeroMainDialog(const QtZeroMainDialog&) = delete;
  QtZeroMainDialog& operator=(const QtZeroMainDialog&) = delete;
  ~QtZeroMainDialog() noexcept;

private:
  Ui::QtZeroMainDialog *ui;

  ///The keys that are currently pressed
  std::set<int> m_keys_pressed;

  ///The sprite of the player
  const std::unique_ptr<QPixmap> m_player_sprite;

  ///The player its coordinats
  int m_player_x;
  int m_player_y;

  ///The timer that presses the pressed keys
  const std::unique_ptr<QTimer> m_timer_press_key;

  ///This event is called when a key is pressed down
  void keyPressEvent(QKeyEvent * e);

  ///This event is called when a key is released
  void keyReleaseEvent(QKeyEvent * e);

  ///This event is called when the screen needs to be (re)draw
  void paintEvent(QPaintEvent * event);

  ///This event is called when the dialog is resized
  void resizeEvent(QResizeEvent*);

private slots:
  void OnTimerPressKey();

};

} //~namespace ribi

#endif // QTGAMEZEROMAINDIALOG_H
