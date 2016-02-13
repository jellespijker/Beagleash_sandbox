# Clear out old data
rm data.csv
rm data_tail.csv
while [ 1 ]; do
    # Log PID output data to CSV
    echo $(date +%H:%M:%S),$(prumsg 31 ro),$(prumsg 31 re),$(prumsg 31 rs) | tee -a data.csv
    # Create readable CSV header
    echo "Time,PWM,RPM,Setpoint" > data_tail_tmp.csv
    # Add last 500 lines to CSV (exclude last line to ensure it is fully written)
    tail -501 data.csv | head -500 >> data_tail_tmp.csv
    # Rename for access by user interface to ensure graph does not attempt to load incomplete data
    mv data_tail_tmp.csv data_tail.csv
done
