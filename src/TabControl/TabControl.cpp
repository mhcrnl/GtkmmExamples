#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->tabControl1.set_size_request(370, 250);
    this->fixed.add(this->tabControl1);
    this->fixed.move(this->tabControl1, 10, 10);

    this->tabControl1.insert_page(this->tabPage1, "tabPage1", 0);
    this->tabControl1.insert_page(this->tabPage2, "tabPage2", 1);
    this->tabControl1.insert_page(this->tabPage3, "tabPage3", 2);

    this->labelPage1.set_label("labelTabPage1");

    this->tabControl1.set_tab_label(this->tabPage1, this->labelPage1);

    this->tabPage1.add(this->fixedTabPage1);

    this->fixedTabPage1.add(this->radioTop);
    this->fixedTabPage1.move(this->radioTop, 10, 10);
    this->radioTop.set_label("Top");
    this->radioTop.set_group(this->radioButtonGroup);
    this->radioTop.signal_toggled().connect([this]() {
       this->tabControl1.set_tab_pos(PositionType::POS_TOP);
    });

    this->fixedTabPage1.add(this->radioLeft);
    this->fixedTabPage1.move(this->radioLeft, 10, 40);
    this->radioLeft.set_label("Left");
    this->radioLeft.set_group(this->radioButtonGroup);
    this->radioLeft.signal_toggled().connect([this]() {
      this->tabControl1.set_tab_pos(PositionType::POS_LEFT);
    });

    this->fixedTabPage1.add(this->radioRight);
    this->fixedTabPage1.move(this->radioRight, 10, 70);
    this->radioRight.set_label("Right");
    this->radioRight.set_group(this->radioButtonGroup);
    this->radioRight.signal_toggled().connect([this]() {
      this->tabControl1.set_tab_pos(PositionType::POS_RIGHT);
    });

    this->fixedTabPage1.add(this->radioBottom);
    this->fixedTabPage1.move(this->radioBottom, 10, 100);
    this->radioBottom.set_label("Bottom");
    this->radioBottom.set_group(this->radioButtonGroup);
    this->radioBottom.signal_toggled().connect([this]() {
      this->tabControl1.set_tab_pos(PositionType::POS_BOTTOM);
    });

    this->set_title("TabControl example");
    this->resize(390, 270);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Notebook tabControl1;
  Label labelPage1;
  Frame tabPage1;
  Frame tabPage2;
  Frame tabPage3;
  RadioButtonGroup radioButtonGroup;
  RadioButton radioTop;
  RadioButton radioLeft;
  RadioButton radioRight;
  RadioButton radioBottom;
  Fixed fixedTabPage1;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
