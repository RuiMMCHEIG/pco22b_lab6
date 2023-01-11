#!/bin/bash

# Get the wireless interface name
interface=$(iw dev | awk '$1=="wlo1"{print $2}')

# Get the signal quality
signal_quality=$(grep -o "[0-9]*" <<< $(iwconfig $interface | grep "Quality="))

# Output the signal quality
echo "Signal Quality: $signal_quality%"
