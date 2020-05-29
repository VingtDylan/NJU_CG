#!/usr/bin/env python
# -*- coding:utf-8 -*-

#                     .::::.                                 
#                   .::::::::.                               
#                  :::::::::::                               
#              ..:::::::::::'                                
#            '::::::::::::'                                  
#              .::::::::::                                   
#         '::::::::::::::..                                  
#              ..::::::::::::.                               
#            ``::::::::::::::::                              
#             ::::``:::::::::'        .:::.                  
#            ::::'   ':::::'       .::::::::.                
#          .::::'      ::::     .:::::::'::::.               
#         .:::'       :::::  .:::::::::' ':::::.             
#        .::'        :::::.:::::::::'      ':::::.           
#       .::'         ::::::::::::::'         ``::::.         
#   ...:::           ::::::::::::'              ``::.        
#  ```` ':.          ':::::::::'                  ::::..     
#                    '.:::::'                    ':'````..  


# 本文件只允许依赖math库
import math


def draw_line(p_list, algorithm):
    """绘制线段

    :param p_list: (list of list of int: [[x0, y0], [x1, y1]]) 线段的起点和终点坐标
    :param algorithm: (string) 绘制使用的算法，包括'DDA'和'Bresenham'，此处的'Naive'仅作为示例，测试时不会出现
    :return: (list of list of int: [[x_0, y_0], [x_1, y_1], [x_2, y_2], ...]) 绘制结果的像素点坐标列表
    """
    x0, y0 = p_list[0] 
    x1, y1 = p_list[1]
    result = []
    if algorithm == 'Naive':
        if x0 == x1:
            if y0 > y1:
                y0, y1 = y1, y0
            for y in range(y0, y1 + 1):
                result.append((x0, y))
        else:
            if x0 > x1:
                x0, y0, x1, y1 = x1, y1, x0, y0
            k = (y1 - y0) / (x1 - x0)
            for x in range(x0, x1 + 1):
                result.append((x, int(y0 + k * (x - x0))))
    elif algorithm == 'DDA':
        if x0 == x1:
            if y0 > y1:
                y0, y1 = y1, y0
            for y in range(y0, y1 + 1):
                result.append((x0, y))
        else:
            dx = x1 - x0
            dy = y1 - y0
            step = max(abs(dx),abs(dy))
            x_step = dx / step
            y_step = dy / step
            for i in range(step + 1):
                result.append((int(x0 + i * x_step), int(y0 + i * y_step)))
    elif algorithm == 'Bresenham':
        dx = abs(x1 - x0)
        dy = abs(y1 - y0)
        def increment(a,b):
            if a > b : return 1
            elif a < b : return -1
            else: return 0
        x_step = increment(x1,x0)
        y_step = increment(y1,y0)
        change = False
        if dy > dx:
            dx,dy = dy,dx
            change = True
        p = 2 * dy - dx 
        x = x0
        y = y0
        for i in range(dx + 1):
            result.append((x,y))
            if p >= 0:
                if not change:
                    y = y + y_step
                else:
                    x = x + x_step
                p -= 2 * dx
            if not change:
                x = x + x_step
            else:
                y = y + y_step
            p += 2 * dy  
    return result


def draw_polygon(p_list, algorithm):
    """绘制多边形

    :param p_list: (list of list of int: [[x0, y0], [x1, y1], [x2, y2], ...]) 多边形的顶点坐标列表
    :param algorithm: (string) 绘制使用的算法，包括'DDA'和'Bresenham'
    :return: (list of list of int: [[x_0, y_0], [x_1, y_1], [x_2, y_2], ...]) 绘制结果的像素点坐标列表
    """
    result = []
    for i in range(len(p_list)):
        line = draw_line([p_list[i - 1], p_list[i]], algorithm)
        result += line
    return result


def draw_ellipse(p_list):
    """绘制椭圆（采用中点圆生成算法）

    :param p_list: (list of list of int: [[x0, y0], [x1, y1]]) 椭圆的矩形包围框左上角和右下角顶点坐标
    :return: (list of list of int: [[x_0, y_0], [x_1, y_1], [x_2, y_2], ...]) 绘制结果的像素点坐标列表
    """
    # 生成对应的四个点
    enumerate_list = [[1,1],[1,-1],[-1,1],[-1,-1]]
    def sub_ellipse(x, y, rx, ry):
        sub_ellipse_result = []
        for mul in enumerate_list:
            sub_ellipse_result.append((int(x + rx * mul[0]),int(y + ry * mul[1])))
        return sub_ellipse_result
    
    result = []
    x0, y0 = p_list[0]
    x1, y1 = p_list[1]
    xmid = (x0 + x1) / 2 
    ymid = (y0 + y1) / 2
    rx = abs(xmid - x0)
    ry = abs(ymid - y0)
    rx2 = rx * rx
    ry2 = ry * ry
    d = ry2 + rx2 * (0.25 - ry)
    dx = 0
    dy = ry
    
    result += sub_ellipse(xmid,ymid,dx,dy)
    while ry2 * (dx + 1) < rx2 * (dy - 0.5):
        if d < 0:
            d += ry2 * (2 * dx + 3)
        else:
            d += (ry2 * (2 * dx + 3) + rx2 * ((-2) * dy + 2))        
            dy -= 1
        dx += 1
        result += sub_ellipse(xmid,ymid,dx,dy)
    
    d=ry2*(dx + 0.5) * (dx + 0.5) + rx2 * (dy - 1) * (dy - 1) - rx2 * ry2;
    while dy > 0:
        if d < 0:
            d += ry2 * (2 * dx + 2) + rx2 * ((-2) * dy + 3)
            dx += 1
        else:
            d += rx2 * ((-2) * dy + 3)
        dy -= 1
        result += sub_ellipse(xmid,ymid,dx,dy)
    return result 


def draw_curve(p_list, algorithm):
    """绘制曲线

    :param p_list: (list of list of int: [[x0, y0], [x1, y1], [x2, y2], ...]) 曲线的控制点坐标列表
    :param algorithm: (string) 绘制使用的算法，包括'Bezier'和'B-spline'（三次均匀B样条曲线，曲线不必经过首末控制点）
    :return: (list of list of int: [[x_0, y_0], [x_1, y_1], [x_2, y_2], ...]) 绘制结果的像素点坐标列表
    """
    def factor(n, k):
        sum=1;
        for i in range(1, n + 1):
            sum *= i
        for i in range(1, k + 1):
            sum /= i
        for i in range(1, n - k + 1):
            sum /= i
        return sum

    def sub_bezier(p_list,n,t):
        x= 0
        y= 0
        bezier_curve=0;
        for i in range(n):
            bezier_curve = factor(n - 1, i) * pow(t, i) * pow(1 - t, n - 1 - i)
            x += p_list[i][0] * bezier_curve;
            y += p_list[i][1] * bezier_curve;
        return [(int(x),int(y))]

    if len(p_list) <= 2: return []
    result = []
    tpoints = 500
    delta = 1.0 / tpoints
    n = len(p_list)
    if algorithm == 'Bezier':
        t = 0.0
        for i in range(tpoints):
            t += delta
            result += sub_bezier(p_list, n, t)
    elif algorithm == 'B-spline': # 三阶
        for i in range(n - 3):
            for j in range(tpoints):
                T = j * delta
                f1 = (-T * T * T + 3 * T * T - 3 * T + 1) / 6
                f2 = (3 * T * T * T - 6 * T * T + 4) / 6
                f3 = (-3 * T * T * T + 3 * T * T + 3 * T + 1) / 6
                f4 = (T * T * T) / 6
                x = f1 * p_list[i][0] + f2 * p_list[i + 1][0] + f3 * p_list[i + 2][0] + f4 * p_list[i + 3][0]
                y = f1 * p_list[i][1] + f2 * p_list[i + 1][1] + f3 * p_list[i + 2][1] + f4 * p_list[i + 3][1]
                result.append((int(x),int(y)))
    return result

def translate(p_list, dx, dy):
    """平移变换

    :param p_list: (list of list of int: [[x0, y0], [x1, y1], [x2, y2], ...]) 图元参数
    :param dx: (int) 水平方向平移量
    :param dy: (int) 垂直方向平移量
    :return: (list of list of int: [[x_0, y_0], [x_1, y_1], [x_2, y_2], ...]) 变换后的图元参数
    """
    result = []
    for (x,y) in p_list:
        x += dx
        y += dy
        result.append((x,y))
    return result

def rotate(p_list, x, y, r):
    """旋转变换（除椭圆外）

    :param p_list: (list of list of int: [[x0, y0], [x1, y1], [x2, y2], ...]) 图元参数
    :param x: (int) 旋转中心x坐标
    :param y: (int) 旋转中心y坐标
    :param r: (int) 顺时针旋转角度（°）
    :return: (list of list of int: [[x_0, y_0], [x_1, y_1], [x_2, y_2], ...]) 变换后的图元参数
    """
    result = []
    r = math.radians(r)
    for (px,py) in p_list:
        rx = px - x
        ry = py - y
        px = x + math.cos(r) * rx + math.sin(r) * ry
        py = y + math.cos(r) * ry - math.sin(r) * rx
        result.append((int(px),int(py)))
    return result

def scale(p_list, x, y, s):
    """缩放变换

    :param p_list: (list of list of int: [[x0, y0], [x1, y1], [x2, y2], ...]) 图元参数
    :param x: (int) 缩放中心x坐标
    :param y: (int) 缩放中心y坐标
    :param s: (float) 缩放倍数
    :return: (list of list of int: [[x_0, y_0], [x_1, y_1], [x_2, y_2], ...]) 变换后的图元参数
    """
    result = []
    for (px,py) in p_list:
        rx = px - x
        ry = py - y
        px = x + rx * s
        py = y + ry * s
        result.append((int(px),int(py)))
    return result


def clip(p_list, x_min, y_min, x_max, y_max, algorithm):
    """线段裁剪

    :param p_list: (list of list of int: [[x0, y0], [x1, y1]]) 线段的起点和终点坐标
    :param x_min: 裁剪窗口左上角x坐标
    :param y_min: 裁剪窗口左上角y坐标
    :param x_max: 裁剪窗口右下角x坐标
    :param y_max: 裁剪窗口右下角y坐标
    :param algorithm: (string) 使用的裁剪算法，包括'Cohen-Sutherland'和'Liang-Barsky'
    :return: (list of list of int: [[x_0, y_0], [x_1, y_1]]) 裁剪后线段的起点和终点坐标
    """
    result = []
    p1,p2 = p_list[0], p_list[1]
    x0, y0, x2, y2 = p1[0], p1[1], p2[0], p2[1]
    if algorithm == 'Cohen-Sutherland':
        left, right, buttom, up = 1, 2, 4, 8
        def encode(x,y):
            c = 0
            if x < x_min: c += left
            elif x > x_max: c += right
            if y < y_min: c += buttom
            elif y > y_max: c += up 
            return c
        if len(p_list) == 0: return []
        code1 = encode(p_list[0][0],p_list[0][1])
        code2 = encode(p_list[1][0],p_list[1][1])
        x, y = 0, 0
        # print(code1,code2)
        while code1 != 0 or code2 != 0:
            if (code1 & code2) != 0:
                break
            code = code1
            if code == 0:code = code2
            if code & left != 0:
                y = y0 + (y2 - y0) * (x_min - x0) / (x2 - x0)
                x = x_min
            elif code & right != 0:
                y = y0 + (y2 - y0) * (x_max - x0) / (x2 - x0)
                x = x_max
            elif code & buttom != 0:
                x = x0 + (x2 - x0) * (y_min - y0) / (y2 - y0)
                y = y_min
            elif code & up != 0:
                x = x0 + (x2 - x0) * (y_max - y0) / (y2 - y0)
                y = y_max
            if code == code1:
                x0 = int(x)
                y0 = int(y)
                p1[0] = x0
                p1[1] = y0
                code1 = encode(x0,y0)
            else:
                x2 = int(x)
                y2 = int(y)
                p2[0] = x2
                p2[1] = y2
                code2 = encode(x2,y2)
        return [p1,p2]
    elif algorithm == 'Liang-Barsky':
        t = [0.0, 1.0]
        deltax, deltay = x2 - x0, y2 - y0
        def clipvisible(q,d,t):
            if q < 0:
                r = d / q
                if r > t[1]:
                    return False
                elif r > t[0]: 
                    t[0] = r
            elif q > 0:
                r = d / q
                if r < t[0]:
                    return False
                elif r < t[1]:
                    t[1] = r
            elif d < 0:
                return False
            return True 
        if not clipvisible(-deltax, x0 - x_min, t):
            return [p1,p2]
        if not clipvisible(deltax, x_max - x0, t):
            return [p1,p2]
        if not clipvisible(-deltay, y0 - y_min, t):
            return [p1,p2]
        if not clipvisible(deltay, y_max - y0, t):
            return [p1,p2]
        p2[0] = int(x0 + t[1] * deltax)
        p2[1] = int(y0 + t[1] * deltay)
        p1[0] = int(x0 + t[0] * deltax)
        p1[1] = int(y0 + t[0] * deltay)
        return [p1,p2]
