Details of Transfer Function Generation for Direct Volume Rendering:
GOAL: The main goal of this project is to formulate a method to generate transfer function for direct volume rendering that works at interactive speed.
ALGORITHM: The algorithm for transfer function generator is designed as a two-step process.
- The first step focuses on the computation of boundary characteristics of the input volume.
- In this step, the algorithm finds the data values corresponding to the object.
- In order to visualize different parts of the object, data values corresponding to the object are divided into multiple subsections using accumulative probability distribution of volume data.
- In the second step, a threshold data value is computed in each subsection. 
- These threshold data values act as piecewise nodes of the opacity transfer function which is given to Direct Volume Rendering algorithm. 
- The user can set opacity to each threshold data value using sliders and visualize the changes in the rendered volume instantly.

Technical Details:
- Programming Language: C++ 
- Toolkits: ITK[Insight Toolkit] and VTK[Visualization Toolkit]
- IDE: Visual Studio 

Demo Video: https://www.youtube.com/watch?v=owXHMHcOYAA

- This project is done in collaboration between IIITD&M Kancheepuram and Lucid Software Limited, Chennai.
- The final software tool developed is contributed to the VTK open source community

- Additional Links: http://www.kovidndt.com/CMS/
