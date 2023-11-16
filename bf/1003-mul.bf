>, >, <<   # Read two digits into cells 1 and 2

+++++ +     # Set cell 3 to 5 and cell 4 to 10

[            # Loop until cell 3 is zero
  >----- --- # Decrement cell 4 and 5 times, decrement cell 3
  >----- ---
  <<-
]

[            # Outer loop
  >[>+>+<<-] # Copy cells 1 and 2 to cells 3 and 4
  [         # Inner loop
    <+>-    # Move the value from cell 4 to cell 3
  ]
  <<-
]

>[-]>+> >+++++ +++++<   # Clear cell 4, increment cell 5, set cell 6 to 70

[            # Loop until cell 6 is zero
  -          # Decrement cell 6
  >-         # Decrement cell 5
  [>>>]      # Move to cell 8
  +++++ +++++ # Increment cell 8 by 10
  <<+        # Move back to cell 5 and increment it
  [<<<]      # Move back to cell 3
  >>>>       # Move to cell 8
]

<-
<+++++ +++++>>>[-<<<->>>]<<<   # Move to cell 8 and perform division to get 8

<+++++ +     # Set cell 3 to 5 and cell 4 to 10

[            # Loop until cell 3 is zero
  >+++++ +++ # Increment cell 4 and 5 times, decrement cell 3
  >[        # Inner loop
    +++++ +++ # Increment cell 5 by 10
    >        # Move to cell 7
    [+++++ +++>]
    <[<]>-   # Move back to cell 4 and decrement it
  ]
  >>[.<<]    # Move to cell 6 and output the result as a character
  <[<<]>>.   # Move back to cell 4 and output the result as a character
]

>>>>>>>>>>>>>>>>>>>>>>>++++++++++.   # Extra characters (not relevant)
