
# Moodvie

 
 > Authors: \<[Gary Zeng](https://github.com/Garrrrrrrrry)\>
 > \<[Selena Arias](https://github.com/sarias-012)\>
 > \<[Kristian Jordan](https://github.com/kristianjordan)\>
 
 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list, start thinking about the features you will implement, what design patterns can help you implement them, and why. If you want to propose your own original idea, you will have to contact an instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). Your project needs to implement at least two design patterns iteratively, which you will have to justify for later phases.The project work should be divided almost equally among team members and each member is expected to work on at least one design pattern (more than one partner may work on a pattern) and some of its test cases. You can of course help each other, but it needs to be clear who will be responsible for which patterns and for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings. While Daily Scrums are not required we highly recommend you practice them too.
 
 > ## Expectations
 > * Incorporate **at least two** distinct design patterns. You need to include at least *one* design pattern that we will teach this session:
 >   * Composite, Strategy, Abstract Factory or Visitor
 > * All design patterns need to be linked together (it can't be two distinct projects)
 > * Your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * Each member of the group must actively participate in the Github Project board and reviewing commited code.
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold one check-in meeting with your lab TA in addition to the final demo.

## Project Description
 > The movie recommender idea is interesting to us because we all enjoy watching tv shows and movies via netflix and other streaming platforms; we want to learn more about how other shows and movies get recommended to us as users. It???s important because no matter where people go online, items/products are constantly being recommended to them based upon their personal data and interests. We believe that being able to understand the process of how things are recommend is critical to our growth and can prepare us for future jobs. In addition, creating a movie recommender would give us experience for incorporating several search and sorting algorithm. We thought it would be interesting to have a movie app that recommends a certain of genre depending on your mood. The features that the project will provide are genre, rating and mood. User's mood determines the input of whether the person is feeling sad, happy or neutral. Based on their mood, the User's mood feature will automatically generate movies for them. Genre is a feature where one is able to manually select a certain type of genre if they happen to op-out in the User's mood feature. 
 > 
 > Languages: c++
 > 
 > Frameworks: GoogleTest
 > 
 > Tools: putty, vim, valgrind
 > 
 > (I/O for program will be through terminal)
 > 
 > Input: User's mood (happy, sad, or neutral), genre (e.g. fantasy, romance, etc), and rating (accepts a number from 0 to 5 [inclusive])
 > 
 > Output: List of movies that matches the description given based on the User???s given mood, genre, and rating.
 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to:
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller actionable development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > The MovieContext class is a context class that implements a singleton design pattern. Its job is to instantiate the MovieContext object, populate movie data into a vector, return the vector, and set and get the strategies. In addition, it contains a class called Movie, which holds the movies attributes (i.e title, rating, duration) and setter and getter functions. It also contains the SearchStrategy and SortStrategy abstract classes, which both implement a strategy design pattern (holds the concrete algorithms for search and sort).SearchStrategy and SortStrategy set the interface for its subclasses that require the implementation of a virtual search and sort function. SearchStrategy concrete classes are SearchTitle, SearchGenre, and SearchRating. SortStrategy concrete classes are SortGenre, SortRating, and SortDuration. We chose to implement MovieContext using the singleton design, due to its ability to instantiate the class once. Doing so helps us write better code, as it allows the repository of movies not to be recreated and manipulated. As for the SearchStrategy and SortStrategy classes, using a strategy design made the most sense. We have three different ways of searching and sorting, with only the strategy of how we search and sort that changes.

 > ![GitHub Logo](projectUML.jpg)
 >  
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design patterns did you use? For each design pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design patterns you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your TA you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
