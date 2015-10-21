
# button request cycle

when Data Latch (DL) goes high

- Request starts

when DL goes low

- set Serial Data (SD) to first button state

Data is sampled from SD for 16 Data Clock cycles. Data sampled on each cycle:

1. B
2. Y
3. Select
4. Start
5. UP
6. DOWN
7. LEFT
8. RIGHT
9. A
10. X
11. L
12. R
13. (none, always high)
14. (none, always high)
15. (none, always high)
16. (none, always high)

when Data Clock (DC) goes high -> low

- button state is sampled from SD by CPU

when DC goes low -> high

- SD is set to next button state
- if there is no next button state (end of 16th cycle) set SD low

