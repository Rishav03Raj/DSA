# Write your MySQL query statement below
with new as(
select 
    id,
    recordDate,
    temperature,
    LAG(temperature,1) over (order by recordDate) as prevDaytemp,
    LAG(recordDate,1) over (order by recordDate) as prevDate
from
Weather
)

select 
    id
    from
    new where temperature-prevDaytemp > 0 and DATEDiff(recordDate,prevDate)=1