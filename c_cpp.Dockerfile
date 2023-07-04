FROM gcc:12.2

COPY . /App

WORKDIR /App

# How to run C ou C++
# If you want it to run docker when you start it, insert the 'RUN':
#gcc program_source_code.c -o executable_file_name
#g++ program_source_code.cpp -o executable_file_name
# (some cases) Assuming that executable_file_name.c ou executable_file_name.cpp exists:
# make executable_file_name
#./executable_file_name

#RUN g++ main.cpp -o main -lpthread

#CMD ["./main"]


# docker build -f c_cpp.Dockerfile -t my-gcc-app ./ && docker run -it --rm -v ./:/App my-gcc-app
