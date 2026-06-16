# Surface Area and Volume Lab

## Lab Description

In this lab, students will write a C++ program to compute the **Total Surface Area (TSA)** and **Volume** of various 3D shapes. The input is read from a file and consists of multiple shape descriptions, one per line. Each shape type has an associated set of parameters, and the program must compute the correct values based on geometric formulas.

### Objectives:
- Use **classes and objects**
- Separate class declaration and implementation into `.h` and `.cpp` files
- Utilize **enums** and clean design patterns
- Read and process input from a structured file
- Output precise TSA and Volume values to **2 decimal places**
- Comply with automated testing using **make-grade** compatible structure (i.e., only modify the 3 files found under /src/ )

### Supported Shapes & Formulas

1. **Cube** (side = l)
   - TSA = 6 × l²
   - Volume = l³

2. **Rectangle (cuboid)** (length = l, width = w, height = h)
   - TSA = 2 × (lw + lh + wh)
   - Volume = l × w × h

3. **Cylinder** (diameter = w, height = h)
   - r = w / 2  
   - TSA = 2πr(r + h)
   - Volume = πr²h

4. **Cone** (diameter = w, height = h)
   - r = w / 2  
   - slant height = √(r² + h²)  
   - TSA = πr(r + slant height)
   - Volume = (1/3)πr²h

5. **Sphere** (diameter = w)
   - r = w / 2  
   - TSA = 4πr²
   - Volume = (4/3)πr³

---

## Input Format

Each line in the input file contains:

```
<shape> <length> <width> <height>
```

- For spheres, cylinders, and cones:  
  - Use `0` for irrelevant dimensions (e.g., length for a sphere)
  - Width represents the diameter
  - Height is used where needed

All input text is lower case, numeric inputs can be double precision. Be sure to handle if we have invalid input types (like a dodechahedron) - TSA and Vol output for invalid types can be 0.

---

## Output Format

The program should print the name of each shape followed by its:
- Total Surface Area (TSA)
- Volume (Vol)

Example:

```
Cube
TSA: 150.00
Vol: 125.00
```

---

## How to Build

From a linux environment (this should have a test argfile.in located in your /target directory, or see how to manually call one of the test files like cube...):
```bash
cd /src
make
cd ../target
./main.out 
./main.out ../tests/cube/argfile.in
```

---

# General Information regarding this repository

## Tips
- Start early
- A discussion of working environment setup can be found at https://cs-mst.gitlab.io/index/ClassGeneral/WorkingEnvironment.html
- A review of student assignment workflow is available at https://notes.manhardt.dev/Assignment%20Tutorial
- Nitty-Gritty details on the auto-grade and CI/CD https://cs-mst.gitlab.io/index/ClassGeneral/ClassroomCode.html 

## Environments for Doing This Assignment

### Mill-classes
- Head to https://git-classes.mst.edu/mrghx4/millclassesoverview for that overview (you can then use the Singularity option from mill-classes desktop instance)!

### Singularity
1. Get on a campus machine or on PuTTY.
2. Clone the repo. Do not clone it in your SDRIVE. It will throw an error.
3. Run `singularity_run.sh` to enter an environment similar to a Docker container.

### GitLab Browser IDE
1. Go to the repo page on GitLab.
2. Press "." key. This should open a new tab with an IDE. You can edit your code here and push it, but you can not run the autograder. To see the autograder output you will have to go look at the GitLab job output.

### Docker
1. Get Docker set up in your terminal.
2. Run `docker_build.sh` to build the Docker image.
3. Run `docker_run.sh` to enter the container.
4. Use `cd your_code/` to enter the repo directory.

### Linux
- If you are already running linux in some way then you may be able to install the dependencies for the autograder and run it locally.

## Auto-grader
### How to run the auto-grader on your machine?
You must have an appropriately configured Linux environment (via Singularity, Docker, or your own VM discussed above), then (from within that machine/container - i.e., you've entered via the referened script files) simply type make from the main assignment folder (not any sub-folder).

### How to run the auto-grader on Gitlab-CI?
Make sure all your files are added, committed, and pushed.
Navigate to the Gitlab web interface to confirm these changes exist on the server.

## How to make sure I'm getting points?
* Click on Build -> Jobs -> the latest job.
* Is it passing, green, etc? 
* What grade does it say you have?
* Whatever grade the latest job says, is what we think you have!

## When is this due?
See Canvas!

