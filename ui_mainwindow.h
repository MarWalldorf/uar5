/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *button_reset;
    QPushButton *button_Simulation_StartStop;
    QHBoxLayout *horizontalLayout_10;
    QSpinBox *spinBox;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox_graph_time;
    QLabel *label_12;
    QPushButton *button_load;
    QPushButton *button_save;
    QVBoxLayout *ust_zadajnik;
    QHBoxLayout *horizontalLayout_5;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label;
    QCheckBox *checkBox_enable_generator;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *button_generator_type;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_9;
    QSpinBox *spin_period;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_8;
    QDoubleSpinBox *doublespin_amp;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_7;
    QDoubleSpinBox *doublespin_const;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *doubleSpin_Fill;
    QLabel *label_11;
    QPushButton *button_ARX_settings;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_2;
    QPushButton *button_integral_type;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QPushButton *button_clear_memory;
    QLabel *label_6;
    QLabel *label_4;
    QPushButton *calka_reset;
    QPushButton *button_summit_settings;
    QPushButton *button_network_setup;
    QLabel *label_network_status;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_3;
    QFrame *Frame_1;
    QHBoxLayout *horizontalLayout_11;
    QFrame *Frame_3;
    QFrame *Frame_4;
    QFrame *Frame_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1270, 885);
        MainWindow->setMinimumSize(QSize(1270, 885));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(-1, 15, 0, 15);
        button_reset = new QPushButton(centralwidget);
        button_reset->setObjectName("button_reset");
        button_reset->setMinimumSize(QSize(182, 35));

        gridLayout->addWidget(button_reset, 1, 0, 1, 1);

        button_Simulation_StartStop = new QPushButton(centralwidget);
        button_Simulation_StartStop->setObjectName("button_Simulation_StartStop");
        button_Simulation_StartStop->setMinimumSize(QSize(80, 35));

        gridLayout->addWidget(button_Simulation_StartStop, 3, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimum(10);
        spinBox->setMaximum(1000);
        spinBox->setSingleStep(10);
        spinBox->setValue(200);

        horizontalLayout_10->addWidget(spinBox);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");

        horizontalLayout_10->addWidget(label_10);


        gridLayout->addLayout(horizontalLayout_10, 7, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        spinBox_graph_time = new QSpinBox(centralwidget);
        spinBox_graph_time->setObjectName("spinBox_graph_time");
        spinBox_graph_time->setMinimum(5);
        spinBox_graph_time->setMaximum(50);
        spinBox_graph_time->setValue(10);

        horizontalLayout_2->addWidget(spinBox_graph_time);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");

        horizontalLayout_2->addWidget(label_12);


        gridLayout->addLayout(horizontalLayout_2, 8, 0, 1, 1);

        button_load = new QPushButton(centralwidget);
        button_load->setObjectName("button_load");
        button_load->setMinimumSize(QSize(80, 35));

        gridLayout->addWidget(button_load, 2, 0, 1, 1);

        button_save = new QPushButton(centralwidget);
        button_save->setObjectName("button_save");
        button_save->setMinimumSize(QSize(182, 35));

        gridLayout->addWidget(button_save, 0, 0, 1, 1);

        ust_zadajnik = new QVBoxLayout();
        ust_zadajnik->setObjectName("ust_zadajnik");
        ust_zadajnik->setContentsMargins(-1, 15, -1, 15);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy);
        doubleSpinBox->setMinimumSize(QSize(86, 25));
        doubleSpinBox->setMinimum(-9999.000000000000000);
        doubleSpinBox->setMaximum(9999.000000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 25));

        horizontalLayout_5->addWidget(label);


        ust_zadajnik->addLayout(horizontalLayout_5);

        checkBox_enable_generator = new QCheckBox(centralwidget);
        checkBox_enable_generator->setObjectName("checkBox_enable_generator");

        ust_zadajnik->addWidget(checkBox_enable_generator);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        button_generator_type = new QPushButton(centralwidget);
        button_generator_type->setObjectName("button_generator_type");
        button_generator_type->setMinimumSize(QSize(0, 25));

        horizontalLayout_6->addWidget(button_generator_type);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 25));

        horizontalLayout_6->addWidget(label_2);


        ust_zadajnik->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        spin_period = new QSpinBox(centralwidget);
        spin_period->setObjectName("spin_period");
        spin_period->setMinimumSize(QSize(0, 25));
        spin_period->setMinimum(1);
        spin_period->setMaximum(9999);

        horizontalLayout_9->addWidget(spin_period);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(0, 25));

        horizontalLayout_9->addWidget(label_7);


        ust_zadajnik->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        doublespin_amp = new QDoubleSpinBox(centralwidget);
        doublespin_amp->setObjectName("doublespin_amp");
        doublespin_amp->setMinimumSize(QSize(0, 25));
        doublespin_amp->setMaximum(9999.000000000000000);

        horizontalLayout_8->addWidget(doublespin_amp);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setMinimumSize(QSize(0, 25));

        horizontalLayout_8->addWidget(label_8);


        ust_zadajnik->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        doublespin_const = new QDoubleSpinBox(centralwidget);
        doublespin_const->setObjectName("doublespin_const");
        doublespin_const->setMinimumSize(QSize(0, 25));
        doublespin_const->setMaximum(9999.000000000000000);

        horizontalLayout_7->addWidget(doublespin_const);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(0, 25));

        horizontalLayout_7->addWidget(label_9);


        ust_zadajnik->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        doubleSpin_Fill = new QDoubleSpinBox(centralwidget);
        doubleSpin_Fill->setObjectName("doubleSpin_Fill");
        doubleSpin_Fill->setMinimumSize(QSize(0, 25));
        doubleSpin_Fill->setMaximum(1.000000000000000);
        doubleSpin_Fill->setValue(0.500000000000000);

        horizontalLayout->addWidget(doubleSpin_Fill);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(label_11);


        ust_zadajnik->addLayout(horizontalLayout);


        gridLayout->addLayout(ust_zadajnik, 9, 0, 1, 1);

        button_ARX_settings = new QPushButton(centralwidget);
        button_ARX_settings->setObjectName("button_ARX_settings");
        button_ARX_settings->setEnabled(true);
        button_ARX_settings->setMinimumSize(QSize(182, 35));

        gridLayout->addWidget(button_ARX_settings, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(-1, 15, -1, 15);
        doubleSpinBox_4 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_4->setObjectName("doubleSpinBox_4");
        doubleSpinBox_4->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(doubleSpinBox_4, 3, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 2, 1, 1, 2);

        doubleSpinBox_2 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");

        gridLayout_2->addWidget(doubleSpinBox_2, 1, 0, 1, 1);

        button_integral_type = new QPushButton(centralwidget);
        button_integral_type->setObjectName("button_integral_type");
        button_integral_type->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(button_integral_type, 2, 3, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 0, 1, 2);

        doubleSpinBox_3 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");

        gridLayout_2->addWidget(doubleSpinBox_3, 2, 0, 1, 1);

        button_clear_memory = new QPushButton(centralwidget);
        button_clear_memory->setObjectName("button_clear_memory");

        gridLayout_2->addWidget(button_clear_memory, 0, 2, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 3, 1, 1, 2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 1, 1, 1, 2);


        verticalLayout_2->addLayout(gridLayout_2);

        calka_reset = new QPushButton(centralwidget);
        calka_reset->setObjectName("calka_reset");

        verticalLayout_2->addWidget(calka_reset);

        button_summit_settings = new QPushButton(centralwidget);
        button_summit_settings->setObjectName("button_summit_settings");

        verticalLayout_2->addWidget(button_summit_settings);

        button_network_setup = new QPushButton(centralwidget);
        button_network_setup->setObjectName("button_network_setup");

        verticalLayout_2->addWidget(button_network_setup);

        label_network_status = new QLabel(centralwidget);
        label_network_status->setObjectName("label_network_status");

        verticalLayout_2->addWidget(label_network_status);

        verticalSpacer_4 = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        formLayout->setLayout(0, QFormLayout::ItemRole::LabelRole, verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        Frame_1 = new QFrame(centralwidget);
        Frame_1->setObjectName("Frame_1");
        Frame_1->setMinimumSize(QSize(0, 400));
        Frame_1->setFrameShape(QFrame::Shape::StyledPanel);
        Frame_1->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_3->addWidget(Frame_1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        Frame_3 = new QFrame(centralwidget);
        Frame_3->setObjectName("Frame_3");
        Frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        Frame_3->setFrameShadow(QFrame::Shadow::Raised);

        horizontalLayout_11->addWidget(Frame_3);

        Frame_4 = new QFrame(centralwidget);
        Frame_4->setObjectName("Frame_4");
        Frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        Frame_4->setFrameShadow(QFrame::Shadow::Raised);

        horizontalLayout_11->addWidget(Frame_4);

        Frame_2 = new QFrame(centralwidget);
        Frame_2->setObjectName("Frame_2");
        Frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        Frame_2->setFrameShadow(QFrame::Shadow::Raised);

        horizontalLayout_11->addWidget(Frame_2);


        verticalLayout_3->addLayout(horizontalLayout_11);


        formLayout->setLayout(0, QFormLayout::ItemRole::FieldRole, verticalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1270, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        button_reset->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        button_Simulation_StartStop->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "ms      interwa\305\202 czasowy", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "s         czas wykresu", nullptr));
        button_load->setText(QCoreApplication::translate("MainWindow", "Wczytaj", nullptr));
        button_save->setText(QCoreApplication::translate("MainWindow", "Zapisz", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Warto\305\233\304\207 zadana", nullptr));
        checkBox_enable_generator->setText(QCoreApplication::translate("MainWindow", "W\305\202\304\205cz generator", nullptr));
        button_generator_type->setText(QCoreApplication::translate("MainWindow", "Sin", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Tryb generatora", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Okres", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Amplituda", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Sta\305\202a", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "wype\305\202nienie", nullptr));
        button_ARX_settings->setText(QCoreApplication::translate("MainWindow", "Ustawienia ARX", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Ti", nullptr));
        button_integral_type->setText(QCoreApplication::translate("MainWindow", "Przed", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ustawienia nastaw", nullptr));
        button_clear_memory->setText(QCoreApplication::translate("MainWindow", "Wyczy\305\233\304\207 pami\304\231\304\207", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Td", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Kp", nullptr));
        calka_reset->setText(QCoreApplication::translate("MainWindow", "Wyczy\305\233\304\207 pami\304\231\304\207 ca\305\202ki", nullptr));
        button_summit_settings->setText(QCoreApplication::translate("MainWindow", "Zapisz ustawienia", nullptr));
        button_network_setup->setText(QCoreApplication::translate("MainWindow", "Konfiguracja Sieci", nullptr));
        label_network_status->setText(QCoreApplication::translate("MainWindow", "Status: Stacjonarny", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
