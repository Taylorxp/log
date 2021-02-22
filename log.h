/***************************************************************************************************
 * FILE: log.h
 *
 * DESCRIPTION: --
 *
 ***************************************************************************************************/
#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>

// 颜色代码: QUOTE: 
// 字背景颜色范围: 40--49              字颜色: 30—39             
//  40: 黑                           30: 黑                 
//  41: 红                           31: 红                
//  42: 绿                           32: 绿                
//  43: 黄                           33: 黄                
//  44: 蓝                           34: 蓝               
//  45: 紫                           35: 紫                 
//  46: 深绿                       36: 深绿                 
//  47: 白色                       37: 白色
// ANSI控制码:
//  QUOTE: 
//       \033[0m   关闭所有属性      
//       \033[1m   设置高亮度      
//       \033[4m   下划线      
//       \033[5m   闪烁      
//       \033[7m   反显      
//       \033[8m   消隐    
//       \033[30m   --   \033[37m   设置前景色     
//       \033[40m   --   \033[47m   设置背景色      
//       \033[nA   光标上移n行     
//       \03[nB   光标下移n行      
//       \033[nC   光标右移n行     
//       \033[nD   光标左移n行

//字体颜色
#define PRINT_FONT_COLOR_BLACK  30
#define PRINT_FONT_COLOR_RED    31
#define PRINT_FONT_COLOR_GREEN  32
#define PRINT_FONT_COLOR_YELLOW 33
#define PRINT_FONT_COLOR_PURPLE 34
#define PRINT_FONT_COLOR_BOTTLE_GREEN 35
#define PRINT_FONT_COLOR_WHITE  36


#define EN_LOG_LOCATE

#define EN_LOG_ERROR
#define EN_LOG_WARN
#define EN_LOG_INFO
#define EN_LOG_VERBO

#ifdef EN_LOG_LOCATE
#define LOG_LOCATE  " @%s:%d\n"
#define LOG_LOCATE_ARG  ,__FILE__,__LINE__
#else
#define LOG_LOCATE  "\n"
#define LOG_LOCATE_ARG  
#endif

#ifdef EN_LOG_ERROR
#define LOG_ERROR(fmt, arg...) printf("\033[31m" fmt " \033[0m\n", ##arg)
// #define LOG_ERROR(fmt, arg...) printf("\033[31m" fmt " \033[0m" LOG_LOCATE, ##arg LOG_LOCATE_ARG)
#else
#define LOG_ERROR(fmt, arg...)
#endif

#ifdef EN_LOG_WARN
#define LOG_WARN(fmt, arg...) printf("\033[33m" fmt " \033[0m\n", ##arg)
#else
#define LOG_WARN(fmt, arg...)
#endif

#ifdef EN_LOG_INFO
#define LOG_INFO(fmt, arg...) printf("\033[0m" fmt "\n", ##arg)
#else
#define LOG_INFO(fmt, arg...)
#endif

#ifdef EN_LOG_VERBO
#define LOG_VERBO(fmt, arg...) printf("\033[0m" fmt "\n", ##arg)
#else
#define LOG_VERBO(fmt, arg...)
#endif




void log_write(const char* format, ...);



#endif