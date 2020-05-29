#!/usr/bin/env python
# -*- coding:utf-8 -*-

#                                        ,s555SB@@&                          
#                                      :9H####@@@@@Xi                        
#                                     1@@@@@@@@@@@@@@8                       
#                                   ,8@@@@@@@@@B@@@@@@8                      
#                                  :B@@@@X3hi8Bs;B@@@@@Ah,                   
#             ,8i                  r@@@B:     1S ,M@@@@@@#8;                 
#            1AB35.i:               X@@8 .   SGhr ,A@@@@@@@@S                
#            1@h31MX8                18Hhh3i .i3r ,A@@@@@@@@@5               
#            ;@&i,58r5                 rGSS:     :B@@@@@@@@@@A               
#             1#i  . 9i                 hX.  .: .5@@@@@@@@@@@1               
#              sG1,  ,G53s.              9#Xi;hS5 3B@@@@@@@B1                
#               .h8h.,A@@@MXSs,           #@H1:    3ssSSX@1                  
#               s ,@@@@@@@@@@@@Xhi,       r#@@X1s9M8    .GA981               
#               ,. rS8H#@@@@@@@@@@#HG51;.  .h31i;9@r    .8@@@@BS;i;          
#                .19AXXXAB@@@@@@@@@@@@@@#MHXG893hrX#XGGXM@@@@@@@@@@MS        
#                s@@MM@@@hsX#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&,      
#              :GB@#3G@@Brs ,1GM@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B,     
#            .hM@@@#@@#MX 51  r;iSGAM@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@8     
#          :3B@@@@@@@@@@@&9@h :Gs   .;sSXH@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:    
#      s&HA#@@@@@@@@@@@@@@M89A;.8S.       ,r3@@@@@@@@@@@@@@@@@@@@@@@@@@@r    
#   ,13B@@@@@@@@@@@@@@@@@@@5 5B3 ;.         ;@@@@@@@@@@@@@@@@@@@@@@@@@@@i    
#  5#@@#&@@@@@@@@@@@@@@@@@@9  .39:          ;@@@@@@@@@@@@@@@@@@@@@@@@@@@;    
#  9@@@X:MM@@@@@@@@@@@@@@@#;    ;31.         H@@@@@@@@@@@@@@@@@@@@@@@@@@:    
#   SH#@B9.rM@@@@@@@@@@@@@B       :.         3@@@@@@@@@@@@@@@@@@@@@@@@@@5    
#     ,:.   9@@@@@@@@@@@#HB5                 .M@@@@@@@@@@@@@@@@@@@@@@@@@B    
#           ,ssirhSM@&1;i19911i,.             s@@@@@@@@@@@@@@@@@@@@@@@@@@S   
#              ,,,rHAri1h1rh&@#353Sh:          8@@@@@@@@@@@@@@@@@@@@@@@@@#:  
#            .A3hH@#5S553&@@#h   i:i9S          #@@@@@@@@@@@@@@@@@@@@@@@@@A. 
#                               Bug祭天,法力无边                             

import sys
from typing import Optional
from PyQt5.QtWidgets import(
    QApplication,
    QMainWindow,
    qApp,
    QGraphicsScene,
    QGraphicsView,
    QGraphicsItem,
    QListWidget,
    QHBoxLayout,
    QWidget,
    QStyleOptionGraphicsItem,
    QFileDialog,
    QColorDialog)
from PyQt5.QtGui import QPainter, QMouseEvent, QColor, QPixmap, QPalette, QBrush, QImage
from PyQt5.QtCore import QRectF, Qt

from PIL import Image
import os, math

import cg_algorithms as alg  

class MyCanvas(QGraphicsView):
    """
    画布窗体类，继承自QGraphicsView，采用QGraphicsView、QGraphicsScene、QGraphicsItem的绘图框架
    """
    def __init__(self, *args):
        super().__init__(*args)
        self.main_window = None
        self.list_widget = None
        self.item_dict = {}
        self.selected_id = ''

        self.status = ''
        self.temp_algorithm = ''
        self.temp_id = ''
        self.temp_item = None
        
        self.color = Qt.black
        
        self.polygon_points = []
        self.polygon_flag = False
        
        self.curve_points = []
        self.curve_flag = False
        
        self.selected_item = None

        self.isDraw = False
        
        self.setStyleSheet("background: transparent")

    def shut_draw(self):
        if self.isDraw:
            if self.status == 'polygon':
                if len(self.polygon_points) > 0:
                    self.polygon_flag = False
                    self.polygon_points = []
                    self.item_dict[self.temp_id] = self.temp_item
                    self.list_widget.addItem(self.temp_id)
                    self.finish_draw()
            elif self.status == 'curve':
                if len(self.curve_points) > 2:
                    self.item_dict[self.temp_id] = self.temp_item
                    self.list_widget.addItem(self.temp_id)
                    self.finish_draw()
                elif len(self.curve_points) > 0:
                    self.finish_draw()
                self.curve_flag = False
                self.curve_points = []
                    
    def shut_edit(self):      
        if self.selected_id != '':
            self.selected_item = self.item_dict[self.selected_id]
            self.selected_item.rotate_flag = False
            self.selected_item.rotate_point_flag = False
            self.selected_item.scale_flag = False
            self.selected_item.scale_point_flag = False
            self.selected_item.clip_flag = False

    def start_draw_line(self, algorithm, item_id):
        self.status = 'line'
        self.temp_algorithm = algorithm
        self.temp_id = item_id

    def start_draw_polygon(self, algorithm, item_id):
        self.status = 'polygon'
        self.temp_algorithm = algorithm
        self.temp_id = item_id
        
    def start_draw_ellipse(self, item_id):
        self.status = 'ellipse'
        self.temp_algorithm = 'Bresenham'
        self.temp_id = item_id

    def start_draw_curve(self, algorithm, item_id):
        self.status = 'curve'
        self.temp_algorithm = algorithm
        self.temp_id = item_id
        
    def start_translate(self):
        self.status = 'translate'

    def start_rotate(self):
        self.status = 'rotate'

    def start_scale(self):
        self.status = 'scale'
    
    def start_clip(self, algorithm):
        self.status = 'clip'
        self.temp_algorithm = algorithm

    def finish_draw(self):
        self.isDraw = False
        self.main_window.item_cnt_in_use = True
        self.temp_id = self.main_window.get_id()

    def clear_selection(self):
        if self.selected_id != '':
            self.item_dict[self.selected_id].selected = False
            self.selected_id = ''

    def selection_changed(self, selected):
        if selected == '': return
        self.main_window.statusBar().showMessage('图元选择： %s' % selected)
        if self.selected_id != '':
            self.item_dict[self.selected_id].selected = False
            self.item_dict[self.selected_id].update()
        self.selected_id = selected
        self.item_dict[selected].selected = True
        self.item_dict[selected].update()
        # self.status = ''
        self.updateScene([self.sceneRect()])

    def mousePressEvent(self, event: QMouseEvent) -> None:
        pos = self.mapToScene(event.localPos().toPoint())
        x = int(pos.x())
        y = int(pos.y())
        if self.status == 'line':
            self.temp_item = MyItem(self.temp_id, self.status, [[x, y], [x, y]], self.temp_algorithm, self.color)
            self.scene().addItem(self.temp_item)
            self.isDraw = True
        elif self.status == 'polygon':
            if event.button() == Qt.LeftButton:
                if not self.polygon_flag:
                    self.polygon_flag = True
                    self.polygon_points.append((x, y))
                    self.polygon_points.append(self.polygon_points[0])
                    self.temp_item = MyItem(self.temp_id, self.status, self.polygon_points, self.temp_algorithm, self.color)
                    self.scene().addItem(self.temp_item)
                    self.isDraw = True
                else:
                    del self.polygon_points[-1]
                    self.polygon_points.append((x, y))
                    self.polygon_points.append(self.polygon_points[0])
            elif event.button() == Qt.RightButton:
                if len(self.polygon_points) > 0:
                    del self.polygon_points[-1]
                    self.polygon_points.append((x, y))
                    self.polygon_points.append(self.polygon_points[0])
                    self.polygon_flag = False
                    self.polygon_points = []
                    self.item_dict[self.temp_id] = self.temp_item
                    self.list_widget.addItem(self.temp_id)
                    self.finish_draw()
        elif self.status == 'ellipse':
            self.temp_item = MyItem(self.temp_id, self.status, [[x, y], [x, y]], self.temp_algorithm, self.color)
            self.scene().addItem(self.temp_item)
            self.isDraw = True
        elif self.status == 'curve':
            if event.button() == Qt.LeftButton:
                if not self.curve_flag:
                    self.curve_flag = True
                    self.curve_points.append((x, y))
                    self.temp_item = MyItem(self.temp_id, self.status, self.curve_points, self.temp_algorithm, self.color)
                    self.scene().addItem(self.temp_item)
                    self.isDraw = True
                else:
                    self.curve_points.append((x, y))
            elif event.button() == Qt.RightButton:
                if len(self.curve_points) > 2:
                    self.curve_points.append((x, y))
                    self.curve_flag = False
                    self.curve_points = []
                    self.item_dict[self.temp_id] = self.temp_item
                    self.list_widget.addItem(self.temp_id)
                    self.finish_draw()
        elif self.status == 'translate':
            if self.selected_id == '':
                pass
            else:
                self.selected_item = self.item_dict[self.selected_id]
                self.selected_item.translateVector = [[x,y],[x,y]]
        elif self.status == 'rotate':
            if self.selected_id == '':
                pass
            else:
                self.selected_item = self.item_dict[self.selected_id]
                if not self.selected_item.rotate_point_flag:
                    self.selected_item.rotate_point_flag = True
                    self.selected_item.rotateVector = [[x,y],[x,y],[x,y]]
                else:
                    self.selected_item.rotate_flag = True
                    self.selected_item.rotateVector[1] = [x,y]
                    self.selected_item.rotateVector[2] = [x,y]
                    self.selected_item.rotate()
        elif self.status == 'scale':
            if self.selected_id == '':
                pass
            else:
                self.selected_item = self.item_dict[self.selected_id]
                if not self.selected_item.scale_point_flag:
                    self.selected_item.scale_point_flag = True
                    self.selected_item.scaleVector = [[x,y],[x,y],[x,y]]
                else:
                    self.selected_item.scale_flag = True
                    self.selected_item.scaleVector[1] = [x,y]
                    self.selected_item.scaleVector[2] = [x,y]
                    self.selected_item.scale()
        elif self.status == 'clip':
            if self.selected_id == '':
                pass
            else:
                self.selected_item = self.item_dict[self.selected_id]
                self.selected_item.clipVector = [[x,y],[x,y]]
        self.updateScene([self.sceneRect()])
        super().mousePressEvent(event)

    def mouseMoveEvent(self, event: QMouseEvent) -> None:
        pos = self.mapToScene(event.localPos().toPoint())
        x = int(pos.x())
        y = int(pos.y())
        if self.status == 'line':
            self.temp_item.p_list[1] = [x, y]
        elif self.status == 'ellipse':
            self.temp_item.p_list[1] = [x, y]
        elif self.status == 'translate':
            if self.selected_id == '':
                pass
            else:
                self.selected_item.translateVector[1] = [x,y]
                self.selected_item.translate_flag = True
                self.selected_item.translate()
        elif self.status == 'rotate':
            if self.selected_id == '':
                pass
            elif self.selected_item.rotate_point_flag:
                self.selected_item.rotateVector[2] = [x,y]
                self.selected_item.rotate()
        elif self.status == 'scale':
            if self.selected_id == '':
                pass
            elif self.selected_item.scale_point_flag:
                self.selected_item.scaleVector[2] = [x,y]
                self.selected_item.scale()
        elif self.status == 'clip':
            if self.selected_id == '':
                pass
            else:
                self.selected_item.clip_flag = True
                self.selected_item.clipVector[1] = [x,y]
                self.selected_item.clip(self.temp_algorithm)
        self.updateScene([self.sceneRect()])
        super().mouseMoveEvent(event)

    def mouseReleaseEvent(self, event: QMouseEvent) -> None:
        if self.status == 'line':
            self.item_dict[self.temp_id] = self.temp_item
            self.list_widget.addItem(self.temp_id)
            self.finish_draw()
        elif self.status == 'ellipse':    
            self.item_dict[self.temp_id] = self.temp_item
            self.list_widget.addItem(self.temp_id)
            self.finish_draw()
        elif self.status == 'translate':
            if self.selected_id == '':
                pass
            else:
                self.selected_item.translate_flag = False
                self.selected_item.translate()
        elif self.status == 'rotate':
            if self.selected_id == '':
                pass
            elif self.selected_item.rotate_flag:
                self.selected_item.rotate_point_flag = False
                self.selected_item.rotate_flag = False
                self.selected_item.rotate()
        elif self.status == 'scale':
            if self.selected_id == '':
                pass
            elif self.selected_item.scale_flag:
                self.selected_item.scale_point_flag = False
                self.selected_item.scale_flag = False
                self.selected_item.scale()
        elif self.status == 'clip':
            if self.selected_id == '':
                pass
            else:
                self.selected_item.clip_flag = False
                self.selected_item.clip(self.temp_algorithm)
        self.updateScene([self.sceneRect()])
        super().mouseReleaseEvent(event)

    def reset_canvas(self) -> None:
        self.selected_id = ''
        self.list_widget.clear()
        self.item_dict.clear()
        for item in self.scene().items():
            self.scene().removeItem(item)

class MyItem(QGraphicsItem):
    """
    自定义图元类，继承自QGraphicsItem
    """
    def __init__(self, item_id: str, item_type: str, p_list: list, algorithm: str = '', color : QColor = None, parent: QGraphicsItem = None):
        """

        :param item_id: 图元ID
        :param item_type: 图元类型，'line'、'polygon'、'ellipse'、'curve'等
        :param p_list: 图元参数
        :param algorithm: 绘制算法，'DDA'、'Bresenham'、'Bezier'、'B-spline'等
        :param parent:
        """
        super().__init__(parent)
        self.id = item_id           # 图元ID
        self.item_type = item_type  # 图元类型，'line'、'polygon'、'ellipse'、'curve'等
        self.p_list = p_list        # 图元参数
        self.algorithm = algorithm  # 绘制算法，'DDA'、'Bresenham'、'Bezier'、'B-spline'等
        self.color = color
        
        self.selected = False
        self.buffer = []
        
        self.translateVector = [[0,0],[0,0]]
        self.translate_flag = False

        self.rotateVector = [[0,0],[0,0],[0,0]]
        self.rotate_flag = False
        self.rotate_point_flag = False

        self.scaleVector = [0,0],[0,0]
        self.scale_flag = False
        self.scale_point_flag = False
        
        self.clipVector = [0,0],[0,0]
        self.clip_flag = False

    def translate(self) -> None:
        dx = self.translateVector[1][0] - self.translateVector[0][0]
        dy = self.translateVector[1][1] - self.translateVector[0][1]
        r = 0
        if not self.translate_flag:
            self.p_list = alg.translate(self.p_list, dx, dy)
            self.buffer.clear()
        else:
            self.buffer = alg.translate(self.buffer, dx, dy)

    def rotate(self) -> None:
        dx1 = self.rotateVector[1][0] - self.rotateVector[0][0]
        dx2 = self.rotateVector[2][0] - self.rotateVector[0][0]
        dy1 = self.rotateVector[1][1] - self.rotateVector[0][1]
        dy2 = self.rotateVector[2][1] - self.rotateVector[0][1]
        def angle(x,y):
            if x != 0 or y != 0:
                cos = x / math.sqrt(x * x + y * y)
                if y >= 0:
                    return math.acos(cos)
                else:
                    return 2*math.pi-math.acos(cos)
            else:
                return 0
        r = -angle(dx2, dy2) + angle(dx1, dy1)    
        r = math.degrees(r)
        if not self.rotate_point_flag and not self.rotate_flag:
            self.p_list = alg.rotate(self.p_list, self.rotateVector[0][0], self.rotateVector[0][1], r)
            self.buffer.clear()
        elif self.rotate_point_flag and self.rotate_flag:
            self.buffer = alg.rotate(self.buffer, self.rotateVector[0][0], self.rotateVector[0][1], r)

    def scale(self) -> None:
        dx1 = self.scaleVector[1][0] - self.scaleVector[0][0]
        dx2 = self.scaleVector[2][0] - self.scaleVector[0][0]
        dy1 = self.scaleVector[1][1] - self.scaleVector[0][1]
        dy2 = self.scaleVector[2][1] - self.scaleVector[0][1]
        def scale_S(dx1,dy1,dx2,dy2):
            if dx1 != 0 or dy1 != 0:
                s = math.sqrt(dx2 * dx2 + dy2 * dy2) / math. sqrt(dx1 * dx1 + dy1 * dy1)
            else:
                s = 1
            return s
        s = scale_S(dx1,dy1,dx2,dy2)
        if not self.scale_point_flag and not self.scale_flag:
            self.p_list = alg.scale(self.p_list, self.scaleVector[0][0], self.scaleVector[0][1], s)
            self.buffer.clear()
        elif self.scale_point_flag and self.scale_flag:
            self.buffer = alg.scale(self.buffer, self.scaleVector[0][0], self.scaleVector[0][1], s)

    def clip(self,algorithm : str) -> None:
        xmin = min(self.clipVector[1][0],self.clipVector[0][0])
        xmax = max(self.clipVector[1][0],self.clipVector[0][0])
        ymin = min(self.clipVector[1][1],self.clipVector[0][1])
        ymax = max(self.clipVector[1][1],self.clipVector[0][1])
        if not self.clip_flag:
            self.p_list = alg.clip(self.p_list, xmin, ymin, xmax, ymax, algorithm)
            self.buffer.clear()
        else:
            pp_list = [[xmin,ymin],[xmax,ymin],[xmax,ymax],[xmin,ymax],[xmin,ymin]]
            self.buffer = alg.draw_polygon(pp_list, 'DDA')
    
    def paint(self, painter: QPainter, option: QStyleOptionGraphicsItem, widget: Optional[QWidget] = ...) -> None:
        painter.setPen(self.color)
        if self.translate_flag or self.rotate_flag or self.scale_flag or self.clip_flag:
            for p in self.buffer:
                painter.drawPoint(*p)
        if self.item_type == 'line':
            item_pixels = alg.draw_line(self.p_list, self.algorithm)
            self.buffer = item_pixels
            for p in item_pixels:
                painter.drawPoint(*p)
            if self.selected:
                painter.setPen(QColor(255, 0, 0))
                painter.drawRect(self.boundingRect())
        elif self.item_type == 'polygon':
            item_pixels = alg.draw_polygon(self.p_list, self.algorithm)
            self.buffer = item_pixels
            for p in item_pixels:
                painter.drawPoint(*p)
            if self.selected:
                painter.setPen(QColor(255, 0, 0))
                painter.drawRect(self.boundingRect())
        elif self.item_type == 'ellipse':
            item_pixels = alg.draw_ellipse(self.p_list)
            self.buffer = item_pixels
            for p in item_pixels:
                painter.drawPoint(*p)
            if self.selected:
                painter.setPen(QColor(255, 0, 0))
                painter.drawRect(self.boundingRect())
        elif self.item_type == 'curve':
            item_pixels = alg.draw_curve(self.p_list, self.algorithm)
            self.buffer = item_pixels
            for p in item_pixels:
                painter.drawPoint(*p)
            if self.selected:
                painter.setPen(QColor(255, 0, 0))
                painter.drawRect(self.boundingRect())

    def boundingRect(self) -> QRectF:
        if self.item_type == 'line':
            x0, y0 = self.p_list[0]
            x1, y1 = self.p_list[1]
            x = min(x0, x1)
            y = min(y0, y1)
            w = max(x0, x1) - x
            h = max(y0, y1) - y
            return QRectF(x - 1, y - 1, w + 2, h + 2)
        elif self.item_type == 'polygon':
            xmin, ymin, xmax, ymax = 1000, 1000, -1, -1 
            points = alg.draw_curve(self.p_list, self.algorithm) + self.p_list
            for (tx, ty) in points:
                xmin = min(xmin,tx)
                xmax = max(xmax,tx)
                ymin = min(ymin,ty)
                ymax = max(ymax,ty)
            w = xmax - xmin
            h = ymax - ymin
            return QRectF(xmin - 1, ymin - 1, w + 2, h + 2)
        elif self.item_type == 'ellipse':
            xmin, ymin, xmax, ymax = 1000, 1000, -1, -1 
            points = alg.draw_ellipse(self.p_list) + self.p_list
            for (tx, ty) in points:
                xmin = min(xmin,tx)
                xmax = max(xmax,tx)
                ymin = min(ymin,ty)
                ymax = max(ymax,ty)
            w = xmax - xmin
            h = ymax - ymin
            return QRectF(xmin - 1, ymin - 1, w + 2, h + 2)
        elif self.item_type == 'curve':
            xmin, ymin, xmax, ymax = 1000, 1000, -1, -1 
            for (tx, ty) in self.p_list:
                xmin = min(xmin,tx)
                xmax = max(xmax,tx)
                ymin = min(ymin,ty)
                ymax = max(ymax,ty)
            w = xmax - xmin
            h = ymax - ymin
            return QRectF(xmin - 1, ymin - 1, w + 2, h + 2)

class MainWindow(QMainWindow):
    """
    主窗口类
    """
    def __init__(self):
        super().__init__()
        self.item_cnt = 0
        self.item_cnt_in_use = True

        # 使用QListWidget来记录已有的图元，并用于选择图元。注：这是图元选择的简单实现方法，更好的实现是在画布中直接用鼠标选择图元
        self.list_widget = QListWidget(self)
        self.list_widget.setMinimumWidth(200)

        # 使用QGraphicsView作为画布
        self.scene = QGraphicsScene(self)
        self.scene.setSceneRect(0, 0, 602, 683)
        self.canvas_widget = MyCanvas(self.scene, self)
        self.canvas_widget.resize(602,683)
        self.canvas_widget.main_window = self
        self.canvas_widget.list_widget = self.list_widget

        # 设置菜单栏
        menubar = self.menuBar()
        file_menu = menubar.addMenu('文件')
        set_pen_act = file_menu.addAction('设置画笔')
        reset_canvas_act = file_menu.addAction('重置画布')
        save_canvas_act = file_menu.addAction('保存画布')
        exit_act = file_menu.addAction('退出')
        draw_menu = menubar.addMenu('绘制')
        line_menu = draw_menu.addMenu('线段')
        line_naive_act = line_menu.addAction('Naive')
        line_dda_act = line_menu.addAction('DDA')
        line_bresenham_act = line_menu.addAction('Bresenham')
        polygon_menu = draw_menu.addMenu('多边形')
        polygon_dda_act = polygon_menu.addAction('DDA')
        polygon_bresenham_act = polygon_menu.addAction('Bresenham')
        ellipse_act = draw_menu.addAction('椭圆')
        curve_menu = draw_menu.addMenu('曲线')
        curve_bezier_act = curve_menu.addAction('Bezier')
        curve_b_spline_act = curve_menu.addAction('B-spline')
        edit_menu = menubar.addMenu('编辑')
        translate_act = edit_menu.addAction('平移')
        rotate_act = edit_menu.addAction('旋转')
        scale_act = edit_menu.addAction('缩放')
        clip_menu = edit_menu.addMenu('裁剪')
        clip_cohen_sutherland_act = clip_menu.addAction('Cohen-Sutherland')
        clip_liang_barsky_act = clip_menu.addAction('Liang-Barsky')

        # 连接信号和槽函数
        # file_menu_action
        set_pen_act.triggered.connect(self.set_pen_action)
        reset_canvas_act.triggered.connect(self.reset_canvas_action)
        save_canvas_act.triggered.connect(self.save_canvas_action)
        exit_act.triggered.connect(qApp.quit)
        # line_menu_action
        line_naive_act.triggered.connect(self.line_naive_action)
        line_dda_act.triggered.connect(self.line_dda_action)
        line_bresenham_act.triggered.connect(self.line_bresenham_action)
        # polygon_menu_action
        polygon_dda_act.triggered.connect(self.polygon_dda_action)
        polygon_bresenham_act.triggered.connect(self.polygon_bresenham_action)
        # ellipse_menu_action
        ellipse_act.triggered.connect(self.ellipse_action)
        # curve_menu_action
        curve_bezier_act.triggered.connect(self.curve_bezier_action)
        curve_b_spline_act.triggered.connect(self.curve_b_spline_action)
        # edit_menu_action
        translate_act.triggered.connect(self.translate_action)
        rotate_act.triggered.connect(self.rotate_action)
        scale_act.triggered.connect(self.scale_action)
        # clip_menu_action
        clip_cohen_sutherland_act.triggered.connect(self.clip_cohen_sutherland_action)
        clip_liang_barsky_act.triggered.connect(self.clip_liang_barsky_action)
        
        self.list_widget.currentTextChanged.connect(self.canvas_widget.selection_changed)
        
        # 设置主窗口的布局
        self.hbox_layout = QHBoxLayout()
        self.hbox_layout.addWidget(self.canvas_widget)
        self.hbox_layout.addWidget(self.list_widget, stretch=1)
        self.central_widget = QWidget()
        self.central_widget.setLayout(self.hbox_layout)
        self.setCentralWidget(self.central_widget)
        self.statusBar().showMessage('空闲')
        self.resize(921, 749)
        self.setWindowTitle('CG Demo')
        
        self.list_widget.setStyleSheet("background: transparent")
        palette = QPalette()
        path =  os.path.dirname(__file__) + "/../imgs/bg.jpg"
        pix = QPixmap(path)
        palette.setBrush(QPalette.Background,QBrush(pix))
        self.setPalette(palette)

    def get_id(self):
        self.canvas_widget.shut_draw()
        self.canvas_widget.shut_edit()
        if self.item_cnt_in_use:
            self.item_cnt += 1
            self.item_cnt_in_use = False
        _id = str(self.item_cnt)
        return _id

    def set_pen_action(self):
        self.canvas_widget.color = QColorDialog.getColor()
    
    def reset_canvas_action(self):
        self.canvas_widget.reset_canvas()
        self.canvas_widget.temp_id = '0'
        self.item_cnt = 1

    def save_canvas_action(self):
        filepath , _ = QFileDialog.getSaveFileName(self,"Save Image","","*.png;; *.bmp;; *.jpg;; *.tif;; *.GIF")
        rect = self.canvas_widget.viewport().rect()
        pixmap = QPixmap(rect.size())
        pixmap.fill(Qt.white)
        self.canvas_widget.viewport().render(pixmap)
        pixmap.save(filepath)
        
    def line_naive_action(self):
        self.canvas_widget.start_draw_line('Naive', self.get_id())
        self.statusBar().showMessage('Naive算法绘制线段')
        self.list_widget.clearSelection()
        self.canvas_widget.clear_selection()
    
    def line_dda_action(self):
        self.canvas_widget.start_draw_line('DDA', self.get_id())
        self.statusBar().showMessage('DDA算法绘制线段')
        self.list_widget.clearSelection()
        self.canvas_widget.clear_selection()  

    def line_bresenham_action(self):
        self.canvas_widget.start_draw_line('Bresenham', self.get_id())
        self.statusBar().showMessage('Bresenham算法绘制线段')
        self.list_widget.clearSelection()
        self.canvas_widget.clear_selection()          

    def polygon_dda_action(self):
        self.canvas_widget.start_draw_polygon('DDA', self.get_id())
        self.statusBar().showMessage('DDA算法绘制多边形')
        self.list_widget.clearSelection()
        self.canvas_widget.clear_selection()  
        
    def polygon_bresenham_action(self):
        self.canvas_widget.start_draw_polygon('Bresenham', self.get_id())
        self.statusBar().showMessage('Bresenham算法绘制多边形')
        self.list_widget.clearSelection()
        self.canvas_widget.clear_selection()  
        
    def ellipse_action(self):
        self.canvas_widget.start_draw_ellipse(self.get_id())
        self.statusBar().showMessage('中点圆算法绘制椭圆')
        self.list_widget.clearSelection()
        self.canvas_widget.clear_selection()  
        
    def curve_bezier_action(self):
        self.canvas_widget.start_draw_curve('Bezier', self.get_id())
        self.statusBar().showMessage('Bezier算法绘制曲线')
        self.list_widget.clearSelection()
        self.canvas_widget.clear_selection()  
    
    def curve_b_spline_action(self):
        self.canvas_widget.start_draw_curve('B-spline', self.get_id())
        self.statusBar().showMessage('B-spline算法绘制曲线')
        self.list_widget.clearSelection()
        self.canvas_widget.clear_selection()  
    
    def translate_action(self):
        self.canvas_widget.start_translate()
        self.statusBar().showMessage('平移图元')
    
    def rotate_action(self):
        self.canvas_widget.start_rotate()
        self.statusBar().showMessage('旋转图元')
    
    def scale_action(self):
        self.canvas_widget.start_scale()
        self.statusBar().showMessage('缩放图元')
    
    def clip_cohen_sutherland_action(self):
        self.canvas_widget.start_clip('Cohen-Sutherland')
        self.statusBar().showMessage('Cohen-Sutherland算法裁剪直线') 
    
    def clip_liang_barsky_action(self):
        self.canvas_widget.start_clip('Liang-Barsky')
        self.statusBar().showMessage('Liang-Barsky算法裁剪直线') 

if __name__ == '__main__':
    app = QApplication(sys.argv)
    mw = MainWindow()
    mw.show()
    sys.exit(app.exec_())
