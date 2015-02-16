# Philosophes

Philosophe Epitech second year project, usage of thread and mutex.

>For a better visualization, a bonus folder contains a GUI with SDL

7 philosophers are around one table.
<ul>
  <li> Each philosopher has one rice bowl in front of him.</li>
  <li> There is a chopstick at the left of each bowl. (So 7 in total).</li>
  <li> A philosopher can only use a chopstick if it is at the left or at the right of his bowl.</li>
  <li> A philosopher goes through three steps :</li>
  <ul>
    <li> Eats with two chopsticks. One left and one right.</li>
    <li> Rests, does not use any chopstick, even if one is available.</li>
    <li> Thinks, uses one and only one chopstick.</li>
  </ul>
</ul>

And beyond that there are a few more rules to guarantee a better digestion - it is
really important for them to be healthy, and a better assimilation of nutritious elements
of the rice - and that’s the real solution about abolition of famishement... but you have
to keep the secret ! :
<ul>
  <li> A philosopher that thinks must eat before resting. In order to get his energy back,
obviously.</li>
  <li> After resting, a philosopher can either eat, or think. But if a neighbor already
thinks, he has the priority to get the collective chopstick.</li>
  <li> The states "think" and "eat" have a maximum duration that you’ll have to deter-
mine.</li>
  <li> A chopstick cannot be used by two philosophers at the same time, for hygienic
reasons, they said.</li>
</ul>
![Alt text](./screenshots/screen1.png?raw=true "Optional Title")

>----------------------------------------------------------------

![Alt text](./screenshots/screen2.png?raw=true "Optional Title")
