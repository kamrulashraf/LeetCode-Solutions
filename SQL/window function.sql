-- Aggregate function

-- avg()
-- max()
-- min()
-- sum()
-- count()

select 
    name,
    sum(amount) over(partition by name order by name) amount
from table


-- rank function

-- row_number()
-- rank()
    -- will rank by same value order by
-- dense_rank()
    -- will dense the rank
-- percent_rank()
-- ntile()

select
    name,
    row_number() over(partition by name order by name) rowno
from table


-- value function

-- lag()
    -- select last row value
-- lead()
    -- select next row value
-- first_value()
    -- select first row value
-- last_value()
    -- select last row value
-- nth_value()
    -- select nth row value

-- lag() example
SELECT ProductId, 
       OrderDate, 
       Quantity, 
       LAG(Quantity) OVER (PARTITION BY ProductId ORDER BY OrderDate) AS "LAG"
FROM [Order] 
INNER JOIN OrderDetail ON [Order].Id = OrderDetail.OrderId 

-- lead example
SELECT ProductId, 
       OrderDate, 
       Quantity, 
       LEAD(Quantity) OVER (PARTITION BY ProductId ORDER BY OrderDate) AS "LEAD"
FROM [Order] 
INNER JOIN OrderDetail ON [Order].Id = OrderDetail.OrderId

-- first value example 
SELECT ProductId, 
       OrderDate, 
       Quantity, 
       FIRST_VALUE(Quantity) OVER (PARTITION BY ProductId ORDER BY OrderDate) AS "FirstValue"
FROM [Order] 
INNER JOIN OrderDetail ON [Order].Id = OrderDetail.OrderId



-- frame clause
-- ROWS BETWEEN <starting_row> AND <ending_row>

-- UNBOUNDED PRECEDING — all rows before the current row in the partition, i.e. the first row of the partition
-- [some #] PRECEDING — # of rows before the current row
-- CURRENT ROW — the current row
-- [some #] FOLLOWING — # of rows after the current row
-- UNBOUNDED FOLLOWING — all rows after the current row in the partition, i.e. the last row of the partition
-- Here’s some examples of how it could be written:

-- ROWS BETWEEN 3 PRECEDING AND CURRENT ROW — this means look back the previous 3 rows up to the current row.
-- ROWS BETWEEN UNBOUNDED PRECEDING AND 1 FOLLOWING — this means look from the first row of the partition to 1 row after the current row
-- ROWS BETWEEN 5 PRECEDING AND 1 PRECEDING — this means look back the previous 5 rows up to 1 row before the current row
-- ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING — this means look from the first row of the partition to the last row of the partition

-- example
SELECT CustomerId, 
       UnitPrice, 
       AVG(UnitPrice) OVER (PARTITION BY CustomerId 
       ORDER BY CustomerId 
       ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) AS “CumAvg”
FROM [Order]
INNER JOIN OrderDetail ON [Order].Id = OrderDetail.OrderId


SELECT CustomerId, 
       UnitPrice, 
       AVG(UnitPrice) OVER (PARTITION BY CustomerId 
       ORDER BY CustomerId 
       ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS “CumAvg”
FROM [Order]
INNER JOIN OrderDetail ON [Order].Id = OrderDetail.OrderId