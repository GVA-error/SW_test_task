#ifndef PAI_MARCHLOG_H
#define PAI_MARCHLOG_H

#include "IO/System/EventLog.hpp"
#include "IO/System/EventLog.hpp"
#include "entities/Unit.h"
#include "mechanics/mechanicsresults.h"

// вывод лога для атак
namespace sw::AI::primitive
{
    using namespace sw::entities;
    void pAI_MoveLog(const Unit& u, mechanics::MarchResult& moveRes, uint32_t tickNumber, sw::EventLog& eventLog);
}


#endif // PAI_MARCHLOG_H
