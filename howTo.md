# How to

## Merge an update

1. start from the main
2. creating a new branch
3. Merge the new feature

   1. go into the main
   1. merge and squash

       ```sh
       git merge --squash branch
       ```
   1. update the remote

       ```sh
       git push origin main
       ```

4. delete la branch

   1. go into the main
   1. local: gb -D branch
   1. remote: gp -d orgin branch

5. Update the others branch from the update of the main

   1. go into your branch
   1. grb main


how to handle a leaks

valgrind : valgrind --leak-check=yes <prog>

leaks : export MallocStackLogging=1
		leaks (other term)

kill process : pkill <prog>