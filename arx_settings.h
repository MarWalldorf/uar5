#ifndef ARX_SETTINGS_H
#define ARX_SETTINGS_H

#include <QDialog>
#include <QMessageBox>
#include "UAR_ARX/ARX_Model.h"
#include <qboxlayout.h>

namespace Ui {
class ARX_Settings;
}

class ARX_Settings : public QDialog
{
    Q_OBJECT
    QVBoxLayout *listLayoutA, *listLayoutB;
    ARX_Model *_model;

    void LoadFromModel();

public:
    explicit ARX_Settings(ARX_Model &, QWidget *parent = nullptr);
    static int counter;
    ~ARX_Settings();

private slots:
    void on_button_wsp_A_add_clicked();

    void on_button_wsp_A_del_clicked();

    void on_button_wsp_A_clear_clicked();

    void on_button_wsp_B_add_clicked();

    void on_button_wsp_B_del_clicked();

    void on_button_wsp_B_clear_clicked();

    void on_Button_save_clicked();

    void on_Button_cancel_clicked();

    void on_ARX_Settings_rejected();

    void on_ARX_Settings_accepted();

private:
    Ui::ARX_Settings *ui;
};

#endif // ARX_SETTINGS_H
