#include "mainwindow.h"

#include <QColorDialog>
#include <QFileDialog>

#include "ui_mainwindow.h"

// #include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->groupBox->setEnabled(false);
  setAcceptDrops(true);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *e) {
  if (e->mimeData()->hasUrls()) {
    e->acceptProposedAction();
  }
}

void MainWindow::dropEvent(QDropEvent *e) {
  foreach (const QUrl &url, e->mimeData()->urls()) {
    QString filename = url.toLocalFile();
    ui->LFileName->setToolTip(filename);
    parse3DOBJ(filename);
  }
}

MainWindow::~MainWindow() {
  on_actionSave_Settings_triggered();
  delete ui;
}

void MainWindow::parse3DOBJ(QString filename) {

  on_actionReset_Settings_triggered();
  ui->openGLWidget->countV = 0;
  ui->openGLWidget->countF = 0;

  Facade->clear();

  try {
    Facade->fileRead(filename.toStdString());
  } catch (...) {
    // std::cout << "Default Exception\n";
    ui->LFileName->setText("ERROR");
  }

  ui->groupBox->setEnabled(true);
  ui->LFileName->setText("File Name: " + filename);
  ui->LFileName->setToolTip(filename);

  ui->LNumberV->setText("Number of Vertices: " +
                        QString::number(Facade->GetVerticesNumber()));
  ui->LNumberE->setText("Number of Edges: " +
                        QString::number(Facade->GetEdgesNumber()));

  if (Facade->IsFileCorrupted()) {
    ui->LNumberV->setText(ui->LNumberV->text() + " (file is corrupted)");
  }

  ui->openGLWidget->countV = Facade->GetVerticesNumber();
  ui->openGLWidget->countF = Facade->GetEdgesNumber();

  ui->openGLWidget->arrayOfCoords = &Facade->FitToWindow();
  ui->openGLWidget->arrayOfEdges = Facade->GetArrayOfEdges();

  ui->openGLWidget->update();

  ui->scaleSB->setMinimum(0.1);
  ui->scaleSB->setValue(1.0);

  emit ui->actionLoad_Settings->trigger();

  if (ui->openGLWidget->isCorrupted) {
    ui->LNumberE->setText(ui->LNumberE->text() + " (file is corrupted)");
  }
}

void MainWindow::on_actionOpen_triggered() {
  QString filter = "All Files (*.*) ;; OBJ Files (*.obj)";
  QString filename =
      QFileDialog::getOpenFileName(this, "Open file...", "", filter);

  parse3DOBJ(filename);
}

void MainWindow::on_actionSave_as_Picture_triggered() {
  QString filter = "JPEG (*.jpeg) ;; BMP (*.bmp)";
  QString path =
      QFileDialog::getSaveFileName(this, "Select where to save...", "", filter);
  if (!path.isNull())
    ui->openGLWidget->grabFramebuffer().save(path, NULL, 100);
}

void MainWindow::on_BBackground_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this);
  if (color.isValid()) {
    ui->openGLWidget->backgroundR = color.redF();
    ui->openGLWidget->backgroundG = color.greenF();
    ui->openGLWidget->backgroundB = color.blueF();
    ui->openGLWidget->update();
  }
}

void MainWindow::on_rotateX_valueChanged(double arg1) {
  Facade->SetTransformArray(arg1 - ui->openGLWidget->rotateX, 0, 0);
  s21::RotateCommand *command = new s21::RotateCommand(
      ui->openGLWidget, &Facade->GetTransformer(), Facade->GetTransformArray());
  command->Execute();
  history.push(command);
}

void MainWindow::on_rotateY_valueChanged(double arg1) {
  Facade->SetTransformArray(0, arg1 - ui->openGLWidget->rotateY, 0);
  s21::RotateCommand *command = new s21::RotateCommand(
      ui->openGLWidget, &Facade->GetTransformer(), Facade->GetTransformArray());
  command->Execute();
  history.push(command);
}

void MainWindow::on_rotateZ_valueChanged(double arg1) {
  Facade->SetTransformArray(0, 0, arg1 - ui->openGLWidget->rotateZ);
  s21::RotateCommand *command = new s21::RotateCommand(
      ui->openGLWidget, &Facade->GetTransformer(), Facade->GetTransformArray());
  command->Execute();
  history.push(command);
}

void MainWindow::on_scaleSB_valueChanged(double arg1) {
  s21::ScaleCommand *command =
      new s21::ScaleCommand(ui->openGLWidget, &Facade->GetTransformer(), arg1);
  command->Execute();
  history.push(command);
}

void MainWindow::on_moveX_valueChanged(double arg1) {
  Facade->SetTransformArray(arg1 - ui->openGLWidget->moveX, 0, 0);
  s21::MoveCommand *command = new s21::MoveCommand(
      ui->openGLWidget, &Facade->GetTransformer(), Facade->GetTransformArray());
  command->Execute();
  history.push(command);
}

void MainWindow::on_moveY_valueChanged(double arg1) {
  Facade->SetTransformArray(0, arg1 - ui->openGLWidget->moveY, 0);
  s21::MoveCommand *command = new s21::MoveCommand(
      ui->openGLWidget, &Facade->GetTransformer(), Facade->GetTransformArray());
  command->Execute();
  history.push(command);
}

void MainWindow::on_moveZ_valueChanged(double arg1) {
  Facade->SetTransformArray(0, 0, arg1 - ui->openGLWidget->moveZ);
  s21::MoveCommand *command = new s21::MoveCommand(
      ui->openGLWidget, &Facade->GetTransformer(), Facade->GetTransformArray());
  command->Execute();
  history.push(command);
}

void MainWindow::on_vSize_valueChanged(double arg1) {
  ui->openGLWidget->pointSize = arg1;
  ui->openGLWidget->update();
}

void MainWindow::on_vNone_toggled(bool checked) {
  if (checked)
    ui->openGLWidget->pointType = 0;
  ui->openGLWidget->update();
}

void MainWindow::on_vCircle_toggled(bool checked) {
  if (checked)
    ui->openGLWidget->pointType = 1;
  ui->openGLWidget->update();
}

void MainWindow::on_vSquare_toggled(bool checked) {
  if (checked)
    ui->openGLWidget->pointType = 2;
  ui->openGLWidget->update();
}

void MainWindow::on_BBackgroundV_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this);
  if (color.isValid()) {
    ui->openGLWidget->pointColorR = color.redF();
    ui->openGLWidget->pointColorG = color.greenF();
    ui->openGLWidget->pointColorB = color.blueF();
    ui->openGLWidget->update();
  }
}

void MainWindow::on_eSolid_toggled(bool checked) {
  if (checked)
    ui->openGLWidget->edgeType = 0;
  ui->openGLWidget->update();
}

void MainWindow::on_eDashed_toggled(bool checked) {
  if (checked)
    ui->openGLWidget->edgeType = 1;
  ui->openGLWidget->update();
}

void MainWindow::on_eWidth_valueChanged(double arg1) {
  ui->openGLWidget->edgeSize = arg1;
  ui->openGLWidget->update();
}

void MainWindow::on_BBackgroundE_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this);
  if (color.isValid()) {
    ui->openGLWidget->edgeColorR = color.redF();
    ui->openGLWidget->edgeColorG = color.greenF();
    ui->openGLWidget->edgeColorB = color.blueF();
    ui->openGLWidget->update();
  }
}

void MainWindow::on_pParallel_toggled(bool checked) {
  if (checked)
    ui->openGLWidget->projectionType = 0;
  ui->openGLWidget->update();
}

void MainWindow::on_pCentral_toggled(bool checked) {
  if (checked)
    ui->openGLWidget->projectionType = 1;
  ui->openGLWidget->update();
}

void MainWindow::on_actionExport_to_GIF_triggered() {
  QString filepath = QFileDialog::getSaveFileName(
      this, "Save as...", "animation.gif", "GIF (*.gif)");

  if (filepath != "") {
    qInfo() << filepath;

    if (isTimerReady) {
      ui->openGLWidget->gif = new QGifImage();
      ui->openGLWidget->timer = new QTimer();
    }
    workTimer(filepath);
    isTimerReady = false;
  }
}

void MainWindow::workTimer(QString filepath) {
  ui->line_3->setToolTip(filepath);
  ui->openGLWidget->timer->start(100);
  connect(ui->openGLWidget->timer, SIGNAL(timeout()), this, SLOT(makeGIF()));
}

void MainWindow::makeGIF() {
  ui->openGLWidget->time++;

  ui->rotateY->setValue(ui->rotateY->value() + 0.1);

  QImage image = ui->openGLWidget->grabFramebuffer().scaled(640, 480);

  ui->openGLWidget->gif->setDefaultDelay(10);
  ui->openGLWidget->gif->addFrame(image);

  if (ui->openGLWidget->time == 50) {
    ui->openGLWidget->time = 0;
    ui->openGLWidget->timer->stop();
    ui->openGLWidget->gif->save(ui->line_3->toolTip());
    image.QImage::bits();
    isTimerReady = true;
    delete ui->openGLWidget->timer;
    delete ui->openGLWidget->gif;
  }
}

void MainWindow::on_actionSave_Settings_triggered() {
  //  QSettings mySettings("config.ini", QSettings::IniFormat);

  QSettings mySettings("school21", "3DViewer20");

  mySettings.beginGroup("Scaling");
  mySettings.setValue("value", ui->scaleSB->value());
  mySettings.endGroup();

  mySettings.beginGroup("Projection");
  if (ui->pParallel->isChecked()) {
    mySettings.setValue("value", "parallel");
  } else {
    mySettings.setValue("value", "central");
  }
  mySettings.endGroup();

  mySettings.beginGroup("Moving");
  mySettings.setValue("xValue", ui->moveX->value());
  mySettings.setValue("yValue", ui->moveY->value());
  mySettings.setValue("zValue", ui->moveZ->value());
  mySettings.endGroup();

  mySettings.beginGroup("Rotating");
  mySettings.setValue("xValue", ui->rotateX->value());
  mySettings.setValue("yValue", ui->rotateY->value());
  mySettings.setValue("zValue", ui->rotateZ->value());
  mySettings.endGroup();

  mySettings.beginGroup("Edges");
  mySettings.setValue("edgeColorR", double(ui->openGLWidget->edgeColorR));
  mySettings.setValue("edgeColorG", double(ui->openGLWidget->edgeColorG));
  mySettings.setValue("edgeColorB", double(ui->openGLWidget->edgeColorB));
  mySettings.setValue("thickness", ui->eWidth->value());
  if (ui->eSolid->isChecked()) {
    mySettings.setValue("value", "solid");
  } else {
    mySettings.setValue("value", "dashed");
  }
  mySettings.endGroup();

  mySettings.beginGroup("Vertices");
  mySettings.setValue("pointColorR", double(ui->openGLWidget->pointColorR));
  mySettings.setValue("pointColorG", double(ui->openGLWidget->pointColorG));
  mySettings.setValue("pointColorB", double(ui->openGLWidget->pointColorB));
  mySettings.setValue("size", ui->vSize->value());

  if (ui->vNone->isChecked()) {
    mySettings.setValue("value", "none");
  } else if (ui->vCircle->isChecked()) {
    mySettings.setValue("value", "circle");
  } else {
    mySettings.setValue("value", "square");
  }
  mySettings.endGroup();

  mySettings.beginGroup("Background");
  mySettings.setValue("backgroundR", double(ui->openGLWidget->backgroundR));
  mySettings.setValue("backgroundG", double(ui->openGLWidget->backgroundG));
  mySettings.setValue("backgroundB", double(ui->openGLWidget->backgroundB));
  mySettings.endGroup();

  mySettings.sync();
}

void MainWindow::on_actionLoad_Settings_triggered() {
  //   QSettings  mySettings("config.TXT", QSettings::IniFormat);

  QSettings mySettings("school21", "3DViewer20");

  double value = 0;

  mySettings.beginGroup("Scaling");
  value = mySettings.value("value", 1).toDouble();
  ui->scaleSB->setValue(value);
  mySettings.endGroup();

  mySettings.beginGroup("Projection");
  if (mySettings.value("value").toString() == "parallel") {
    ui->pParallel->setChecked(true);
  }
  if (mySettings.value("value").toString() == "central") {
    ui->pCentral->setChecked(true);
  } else {
    ui->pParallel->setChecked(true);
  }
  mySettings.endGroup();

  mySettings.beginGroup("Moving");
  value = mySettings.value("xValue", 0).toDouble();
  ui->moveX->setValue(value);
  value = mySettings.value("yValue", 0).toDouble();
  ui->moveY->setValue(value);
  value = mySettings.value("zValue", 0).toDouble();
  ui->moveZ->setValue(value);
  mySettings.endGroup();

  mySettings.beginGroup("Rotating");
  value = mySettings.value("xValue", 0).toDouble();
  ui->rotateX->setValue(value);
  value = mySettings.value("yValue", 0).toDouble();
  ui->rotateY->setValue(value);
  value = mySettings.value("zValue", 0).toDouble();
  ui->rotateZ->setValue(value);
  mySettings.endGroup();

  mySettings.beginGroup("Edges");
  value = mySettings.value("edgeColorR", 0).toDouble();
  ui->openGLWidget->edgeColorR = float(value);
  value = mySettings.value("edgeColorG", 0).toDouble();
  ui->openGLWidget->edgeColorG = float(value);
  value = mySettings.value("edgeColorB", 0).toDouble();
  ui->openGLWidget->edgeColorB = float(value);

  value = mySettings.value("thickness", 1).toDouble();
  ui->eWidth->setValue(value);

  if (mySettings.value("value").toString() == "solid") {
    ui->eSolid->setChecked(true);
  }
  if (mySettings.value("value").toString() == "dashed") {
    ui->eDashed->setChecked(true);
  } else {
    ui->eSolid->setChecked(true);
  }
  mySettings.endGroup();

  mySettings.beginGroup("Vertices");

  value = mySettings.value("pointColorR", 0).toDouble();
  ui->openGLWidget->pointColorR = float(value);
  value = mySettings.value("pointColorG", 0).toDouble();
  ui->openGLWidget->pointColorG = float(value);
  value = mySettings.value("pointColorB", 0).toDouble();
  ui->openGLWidget->pointColorB = float(value);

  value = mySettings.value("size", 1).toDouble();
  ui->vSize->setValue(value);

  if (mySettings.value("value").toString() == "none") {
    ui->vNone->setChecked(true);
  } else if (mySettings.value("value").toString() == "circle") {
    ui->vCircle->setChecked(true);
  } else if (mySettings.value("value").toString() == "square") {
    ui->vSquare->setChecked(true);
  } else {
    ui->vNone->setChecked(true);
  }
  mySettings.endGroup();

  mySettings.beginGroup("Background");
  value = mySettings.value("backgroundR", 0.92549).toDouble();
  ui->openGLWidget->backgroundR = float(value);
  value = mySettings.value("backgroundG", 0.925475).toDouble();
  ui->openGLWidget->backgroundG = float(value);
  value = mySettings.value("backgroundB", 0.92549).toDouble();
  ui->openGLWidget->backgroundB = float(value);
  mySettings.endGroup();

  ui->openGLWidget->update();
}

void MainWindow::on_actionReset_Settings_triggered() {
  ui->scaleSB->setValue(1);
  ui->pParallel->setChecked(true);

  ui->moveX->setValue(0);
  ui->moveY->setValue(0);
  ui->moveZ->setValue(0);

  ui->rotateX->setValue(0);
  ui->rotateY->setValue(0);
  ui->rotateZ->setValue(0);

  ui->openGLWidget->edgeColorR = float(0);
  ui->openGLWidget->edgeColorG = float(0);
  ui->openGLWidget->edgeColorB = float(0);

  ui->eWidth->setValue(1);
  ui->eSolid->setChecked(true);

  ui->openGLWidget->pointColorR = float(0);
  ui->openGLWidget->pointColorG = float(0);
  ui->openGLWidget->pointColorB = float(0);

  ui->vSize->setValue(1);
  ui->vNone->setChecked(true);

  ui->openGLWidget->backgroundR = float(0.92549);
  ui->openGLWidget->backgroundG = float(0.925475);
  ui->openGLWidget->backgroundB = float(0.92549);

  ui->openGLWidget->rotateX = 0;
  ui->openGLWidget->rotateY = 0;
  ui->openGLWidget->rotateZ = 0;

  ui->openGLWidget->projectionType = 0;

  ui->openGLWidget->scaleRatio = 1;

  ui->openGLWidget->moveX = 0;
  ui->openGLWidget->moveY = 0;
  ui->openGLWidget->moveZ = 0;

  ui->openGLWidget->time = 0;

  ui->openGLWidget->edgeType = 0;
  ui->openGLWidget->edgeSize = 1;

  ui->openGLWidget->pointType = 0;
  ui->openGLWidget->pointSize = 1;

  ui->openGLWidget->arrayOfCoords = &Facade->FitToWindow();

  ui->openGLWidget->update();

  std::stack<s21::Command *> tmp;
  history.swap(tmp);
}

void MainWindow::on_actionUndo_triggered() {
  if (!history.empty()) {
    history.top()->Undo();
    history.pop();
  }
  if (!history.empty()) {
    history.top()->Undo();
    history.pop();
  }

  ui->moveX->setValue(ui->openGLWidget->moveX);
  ui->moveY->setValue(ui->openGLWidget->moveY);
  ui->moveZ->setValue(ui->openGLWidget->moveZ);

  ui->rotateX->setValue(ui->openGLWidget->rotateX);
  ui->rotateY->setValue(ui->openGLWidget->rotateY);
  ui->rotateZ->setValue(ui->openGLWidget->rotateZ);

  ui->scaleSB->setValue(ui->openGLWidget->scaleRatio);
}
