,>     # Read the first digit and move to the second cell
,      # Read the second digit
[      # Start loop
  -    # Clear the third cell
  <    # Move to the first digit
  +    # Increment the first digit (will be used as a counter for the second digit)
  >    # Move to the second digit
  -    # Decrement the second digit
  >>   # Move to the third cell
]      # End loop

<<[->>+<<]>>[-<+>]   # Multiply the two digits and store the result in the first cell

<.     # Output the result as a character
