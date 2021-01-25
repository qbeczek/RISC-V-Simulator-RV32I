#RISC-V-Simulator_RV32I

To avoid conflicts I suggest to use branches for each `.c` module.

1. Make sure you're up to date with the latest commit on `main` branch

`git checkout main` - if you are not on this branch yet
`git fetch`

If there is no output, you're up to date. If not, pull changes:

`git pull`

2. Create your branch

I suggest to use:

`git checkout -b branch_name`

which is a shorthand for:

Creating new branch:
`git branch branch_name`
...and switching to it:
`git checkout branch_name`

3. When you're done with changes

Add them to git:
`git add filename.c`

Commit changes:
`git commit -m 'descriptive message'`

Then push your branch to our repo:
`git push origin branch_name --force-with-lease`

4. Create PR and merge your branch to the `main` branch

Go to GitHub -> Code -> branches
Find your branch and `Create Pull Request`
If there are no conflicts, click `Merge`
