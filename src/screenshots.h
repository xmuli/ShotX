#ifndef SCREENSHOTS_H
#define SCREENSHOTS_H

#include "systeminfo.h"
#include <QPoint>
#include <QWidget>


enum ScreenType {
    Select = 0x0001,                              // 选择截图矩形
    Move = 0x0002,                               // 移动矩形区域
    SetSize = 0x0004                             // 设置矩形大小
};
Q_DECLARE_FLAGS(ScreenTypes, ScreenType)         // 枚举 ScreenType 生成宏 ScreenTypes
Q_DECLARE_OPERATORS_FOR_FLAGS(ScreenTypes)       // 重载宏 ScreenTypes 的 |() 函数

class ScreenShots : public QWidget
{
    Q_OBJECT
public:
    ScreenShots();
    ~ScreenShots();

    void init();
    QRect setCurrRect();                         // 判断当前矩形的大小
    ScreenTypes isInArea(QPoint pos);


private:
    const QPixmap *pixmap();
    const QPixmap *basePixmap();                 // 背景图
    QPoint offset();
    void drawScreenRect(QRect &rect, QPainter &pa); //绘画截图黑白线框

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QRect  m_rect;
    QPoint m_staPos;
    QPoint m_endPos;
    QPoint m_moveStaPos;
    QPoint m_moveEndPos;
    ScreenTypes m_screenType;

    QPixmap    *m_pixmap;         // 原图
    QPixmap    *m_basePixmap;     // 背景图(= 原图 + 灰色)
    QPixmap    *m_savePixmap;     // 保存图；
    SystemInfo *m_sysInfo;

};

#endif // SCREENSHOTS_H