-- Table: Activity

-- +--------------+---------+
-- | Column Name  | Type    |
-- +--------------+---------+
-- | player_id    | int     |
-- | device_id    | int     |
-- | event_date   | date    |
-- | games_played | int     |
-- +--------------+---------+
-- (player_id, event_date) is the primary key of this table.
-- This table shows the activity of players of some games.
-- Each row is a record of a player who logged in and played a number of games (possibly 0) before logging out on someday using some device.
 

-- Write an SQL query to report the first login date for each player.

-- Return the result table in any order.

-- The query result format is in the following example.


-- SOLUTION 1
SELECT PLAYER_ID, MIN(EVENT_DATE) AS FIRST_LOGIN
FROM ACTIVITY
GROUP BY PLAYER_ID

-- SOLUTION 2

SELECT
    A.PLAYER_ID,
    A.EVENT_DATE AS FIRST_LOGIN
    FROM 
    (SELECT PLAYER_ID,
        EVENT_DATE,
        ROW_NUMBER() OVER (PARTITION BY PLAYER_ID ORDER BY EVENT_DATE) AS ROWNUM
    FROM ACTIVITY
    ) AS A
WHERE A.ROWNUM = 1


 