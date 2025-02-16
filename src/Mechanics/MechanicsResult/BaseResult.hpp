#pragma once


namespace sw::mechanics
{
    // Минимальный результат для функционирования механик.
    struct BaseResult
    {
        bool     f_activity          = false;      // механика была воспроизведена.
        bool     f_isMechanicAllowed = true;       // механика не была запрещена намеренно.
    };
}
