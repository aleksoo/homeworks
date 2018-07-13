#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QString>
#include <QProcess>
#include <QList>

class Board;
class QLineEdit;
class QPushButton;
class QSlider;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    void setup();
    void updateButtons();
    void processMoves();

protected slots:
    void sltBlueReady();
    void sltRedReady();
    void sltBlueTimeout();
    void sltRedTimeout();
    void sltNextMove();
    void sltSelectBlue();
    void sltSelectRed();
    void sltSelectMap();
    void sltStart();
    void sltStop();
    void sltSliderMoved(int move);

private:
    Q_DISABLE_COPY(MainWindow)

    QProcess m_blueProcess;
    QProcess m_redProcess;

    QTimer m_moveTimer;
    QTimer m_blueTimer;
    QTimer m_redTimer;

    Board* m_board;

    QLineEdit* m_blueEdit;
    QLineEdit* m_redEdit;
    QLineEdit* m_mapEdit;
    QPushButton* m_startButton;
    QPushButton* m_stopButton;
    QPushButton* m_blueButton;
    QPushButton* m_redButton;
    QPushButton* m_mapButton;
    QSlider* m_slider;

    QVector<QString> m_map;
    QVector<QString> m_blackMap;
    QList<QVector<QString> > m_movesList;

    bool m_isStarted;

    bool m_blueMoved;
    bool m_redMoved;

    char m_blueMove;
    char m_redMove;
};

#endif // MAINWINDOW_H
