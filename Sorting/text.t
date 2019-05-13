DoPeriodicTask is defined in entityscript.lua.

local per = scheduler:ExecutePeriodic(time, fn, nil, initialdelay, self.GUID, self, ...)
and the issue is related to this line. In scheduler.lua

function Scheduler:ExecutePeriodic(period, fn, limit, initialdelay, id, ...)
    local list, nexttick = self:GetListForTimeFromNow(initialdelay or period)
    local periodic = Periodic(fn, period, limit, id, nexttick, ...)
    list[periodic] = true
    periodic.list = list
    return periodic
end

and self:GetListForTimeFromNow() decides when to start next thread.

function Scheduler:GetListForTimeFromNow(dt)
    local nowtick = GetTick()
    local wakeuptick = math.floor( (GetTime()+dt)/GetTickTime() )
    if wakeuptick <= nowtick then
        wakeuptick = nowtick+1
    end

    local list = scheduler.attime[wakeuptick]
    if not list then
        list = {}
        scheduler.attime[wakeuptick] = list
    end
    return list, wakeuptick
end
As you can see, 

local wakeuptick = math.floor( (GetTime()+dt)/GetTickTime() )
wakeuptick is divided and rounded off by GetTickTime(). So, this engrafts every thread into the game tick. 
Note that (1 game tick) = FRAMES = float number 0.333... = 0.333...seconds in real time(if no lag)

if wakeuptick <= nowtick then
  wakeuptick = nowtick+1
end
and if wakeuptick is smaller than nowtick(smaller than FRAMES )