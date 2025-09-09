# Write your MySQL query statement below
select s.user_id , round(coalesce(ans.cf/ans.tt,0),2)confirmation_rate from Signups s 
left join 
(
select user_id , 
count(case when action='confirmed' then 1 end) as cf ,
count(*) as tt from 
Confirmations group by user_id 
) as ans
on s.user_id = ans.user_id;