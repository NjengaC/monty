,>,          # Read two digits into cells 1 and 2

>++++++      # Set cell 3 to 6

[            # Loop until cell 3 is zero
  >++++++++  # Increment cell 4 by 8
  <-         # Decrement cell 3
]
>>           # Move to cell 5

++++++       # Set cell 5 to 48

[            # Loop until cell 5 is zero
  >++++++++  # Increment cell 6 by 8
  <-         # Decrement cell 5
]
>            # Move to cell 7

[            # Loop until cell 7 is zero
  -          # Decrement cell 7
  <<<<-      # Move to cell 3 and decrement it
  <          # Move to cell 2
  -          # Decrement cell 2
  >>>>>      # Move to cell 7
]
<<<<<        # Move back to cell 2

[            # Loop until cell 2 is zero
  >          # Move to cell 3
  [          # Inner loop
    >+       # Increment cell 4
    >>+      # Increment cell 5
    <<<-     # Move to cell 2 and decrement it
  ]
  >>>        # Move to cell 6
  [          # Inner loop
    -        # Decrement cell 6
    <<<+     # Move to cell 2 and increment it
    >>>      # Move to cell 7
  ]
  <<<<-      # Move back to cell 3
]
>>           # Move to cell 5

[            # Loop until cell 5 is zero
  -          # Decrement cell 5
  >+         # Increment cell 6
  <          # Move back to cell 4
]
>.           # Output the result in cell 4 as a character
