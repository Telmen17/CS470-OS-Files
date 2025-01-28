# @author: Telmen Enkhtuvshin
# Shell script to automate file creation

#Creating directory name variable
current_datetime=$(date +"%Y-%m-%d_%H:%M:%S")

# Creating main directory
mkdir -p "$current_datetime"

# List of programming languages
languages=("Python" "Java" "C++" "JavaScript" "Ruby" "C" "Swift" "Kotlin" "PHP" "Rust")

# Print a confirmation message
echo "Directory '$current_datetime' created successfully..."

# Create subdirectories
for i in {101..110}; do
    # Subdirectory name
    subdir="$current_datetime/file$i"
    mkdir -p "$subdir"

    # Subdirectory creation confirmation
    echo "Subdirectory $subdir created successfully..."

    # Create files inside the subdirectory
    for j in {501..510}; do
        # File name
        file_name="$subdir/tuser$j.txt"
        # Index of list
        langIndex=$(( (j - 501) % ${#languages[@]} ))
        # Creating file with
        echo "${languages[$langIndex]}" > "$file_name"

        # File creation confirmation
        echo "File $file_name created and written successfully..."
    done
done

# Print a confirmation message
echo "Subdirectories file101 to file110 with tuser501.txt to tuser510.txt files successfully created inside '$current_datetime'..."
