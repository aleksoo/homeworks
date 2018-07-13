#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QString>
#include <QVector>

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget* parent = nullptr);
    ~Board();

public slots:
    void draw(const QVector<QString>& map);

protected:
    void paintEvent(QPaintEvent* event);

    enum { Scale = 20, Margin = 3 };

    void drawSquare(QPainter& painter, int x, int y, char c);

private:
    Q_DISABLE_COPY(Board)

    QVector<QString> m_map;
};

#endif // BOARD_H
