-- 코드를 입력하세요
SELECT * 
FROM PLACES 
WHERE HOST_ID in 
(SELECT HOST_ID 
 FROM PLACES 
 GROUP BY HOST_ID HAVING count(*) > 1);
