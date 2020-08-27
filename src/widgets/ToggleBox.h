#ifndef DISPAR_TOGGLE_BOX_H
#define DISPAR_TOGGLE_BOX_H

#include <QWidget>

class QScrollArea;
class QLayout;
class QToolButton;

namespace dispar {

class ToggleBox : public QWidget {
  Q_OBJECT

public:
  ToggleBox(const QString &title, const QString &settingsKey, QWidget *parent = nullptr);
  ~ToggleBox() override;

  void setContentLayout(QLayout *layout);

  void setCollapsed(bool collapsed = true);
  void setExpanded(bool expanded = true);

  [[nodiscard]] bool isCollapsed() const;
  [[nodiscard]] bool isExpanded() const;

signals:
  void expanded();
  void collapsed();
  void stateChanged(bool collapsed);

protected:
  void showEvent(QShowEvent *event) override;

private:
  void createLayout();

  QString title, settingsKey;
  QToolButton *toggleButton;
  QScrollArea *contentWidget;
};

} // namespace dispar

#endif // DISPAR_TOGGLE_BOX_H
