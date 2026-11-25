#include <QApplication>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Personal Download Manager");
    window.resize(900, 600);

    auto *layout = new QVBoxLayout(&window);
    auto *label = new QLabel("Personal Download Manager");

    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    window.show();

    return app.exec();
}
