# Use the official Python image from the Docker Hub
FROM python:3.9-slim

# Set the working directory in the container
WORKDIR /usr/src/app

# Copy the requirements file into the container
COPY requirements.txt ./

# Install the dependencies
RUN apt-get update && apt-get install -y \
    xvfb \
    && pip install --no-cache-dir -r requirements.txt

# Copy the rest of the application code into the container
COPY . .

# Command to run the analysis script with Xvfb
CMD ["sh", "-c", "xvfb-run -a python analysis/analysis.py"]