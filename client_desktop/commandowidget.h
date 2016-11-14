/****************************************************************************
Copyright 2016 Ricardo Quesada
http://github.com/ricardoquesada/unijoysticle

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
****************************************************************************/

#pragma once

#include "basejoymode.h"

#include <QImage>

QT_BEGIN_NAMESPACE
class QGamepad;
QT_END_NAMESPACE


class CommandoWidget : public BaseJoyMode
{
    Q_OBJECT
public:
    explicit CommandoWidget(QWidget *parent = 0);
    void enable(bool enabled);

signals:

public slots:
    void onGamepadConnected(int id);
    void onGamepadDisconnected(int id);

    void onAxisLeftXChanged(double value);
    void onAxisLeftYChanged(double value);
    void onAxisRightXChanged(double value);
    void onAxisRightYChanged(double value);
    void onButtonAChanged(bool pressed);
    void onButtonBChanged(bool pressed);
    void onButtonXChanged(bool pressed);
    void onButtonYChanged(bool pressed);
    void onButtonUpChanged(bool pressed);
    void onButtonDownChanged(bool pressed);
    void onButtonLeftChanged(bool pressed);
    void onButtonRightChanged(bool pressed);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

    void registerGamepad();
    void unregisterGamepad();

    void processEvents();
    void send();


    QImage _whiteImages[3];
    QImage _redImages[3];

    uint8_t _joyState[2];

    int _gamepadId;
    QGamepad* _gamepad;

    float _zoomLevel;
};
