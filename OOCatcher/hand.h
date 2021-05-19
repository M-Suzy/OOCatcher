#pragma once
#include "line_segment.h"
#include "body_parts.h"
class hand :
    public body_parts
{
private:
    line_segment fingers[5];
};

