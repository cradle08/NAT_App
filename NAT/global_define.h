#ifndef GLOBAL_DEFINE_H
#define GLOBAL_DEFINE_H


class WorkFlow_Start;
class WorkFlow_Temp;
class WorkFlow_TempData;
class WorkFlow_Goto;
class WorkFlow_End;


/**
  * @brief 设置工作流程类型
  * @param
  * @retval
  */
typedef enum
{
    WORKFLOW_TYPE_Start  = 0,
    WORKFLOW_TYPE_Temp,
    WORKFLOW_TYPE_TempData,
    WORKFLOW_TYPE_Goto,
    WORKFLOW_TYPE_End,
    WORKFLOW_TYPE_END,

}WorkFlow_Type_e;



//最大温控上限 100°
#define MAX_TEMPERATURE_VALUE   100.0

//温控最大应许时间 3600秒
#define MAX_TEMPERATURE_TIME   3600






#endif // GLOBAL_DEFINE_H


