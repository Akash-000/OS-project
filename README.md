
consider a scheduling approach which is non pre-emptive similar to shortest job next in nature. the priority of each job is dependent on its estimated run time, and also the amount of time it has spent waiting. jobs gain higher priority the longer they wait, which prevents indefinite postponement. the jobs that have spent a long time waiting compete against those estimated to have short run times. the priority can be computed as : priority = 1+ waiting time / estimated run time write a program to implement such an algorithm.
