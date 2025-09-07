# Write your MySQL query statement below
select t.machine_id , round(avg(t.endtime)-avg(t.starttime),3) as processing_time from
(
select a.machine_id , a.process_id, a.activity_type,a.timestamp as starttime , b.timestamp as endtime
from activity a join activity b on 
    a.machine_id = b.machine_id and
    a.process_id = b.process_id and
    a.activity_type = 'start' and   
    b.activity_type  ='end'
) t
group by t.machine_id