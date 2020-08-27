#ifndef DISPAR_TAGS_EDIT_H
#define DISPAR_TAGS_EDIT_H

#include <QWidget>

class QLineEdit;
class QListWidget;

namespace dispar {

class TagItemDelegate;

class TagsEdit : public QWidget {
  Q_OBJECT

public:
  TagsEdit();
  ~TagsEdit() override;

  void setAddress(quint64 address);

protected:
  bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
  void onReturnPressed();

  void updateTags();

private:
  void createLayout();
  void removeTag();

  quint64 address_;
  QListWidget *listWidget;
  QLineEdit *lineEdit;
  TagItemDelegate *itemDelegate;
};

} // namespace dispar

#endif // DISPAR_TAGS_EDIT_H
