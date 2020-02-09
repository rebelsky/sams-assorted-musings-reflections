---
title: Long-term projections
number: 
tags: [Grinnell](index-grinnell)
blurb: Doing the math on the back of an envelope, or something like that.
version: 0.1
released: 
current: 2020-02-09
---
Grinnell has something like a two-billion-dollar endowment.  With an
endowment that large, do we really need donations?  That's something
I know many of our alumni ask.  It's also something I ask myself.

Some donations are useful because they support things not currently
in budget lines.  For example, I donate to the CS department so that
we have funds to take research students to meals or offer snacks at
class presentations [1].  I also donate to the student food bank, even
though I wish that it didn't have to exist.

But what about to the base endowment?  Are those donations also 
necessary?  In my early years at Grinnell, I didn't think so [2].
However, when I think about long-term projections, I can see why
the Trustees and others ask us to donate.  Or at least I think I do.

Let me do the math.  Or at least some "back of the envelope" calculations.

We'll say that our endowment is $2,000,000,000.  Wow.  That's a lot of
zeroes.  We'll assume that we take 4% from the endowment each year.  I
suppose we could take a bit more, but it's enough for now.  We'll assume
that our investment strategy provides a return of 5%.  I know that it's
been higher in most recent years, but I hear that most analysts think
higher rates will be difficult in the future, particularly if we adjust
for the upcoming downturn.

What other assumptions should I make?  Let's assume that our current
budget is $100,000,000 per year, that we need the endowment to cover
55% of the budget, and that the budget grows at 3% annually.  That
last number may be a bit conservative; most of our expenses are
related to personnel, and things like health care grow at a much
higher rate.  Are the numbers themselves reasonable?  Our 2018
budget was about $130,000,000 and the endowment paid a little less
than 57%.  It's a starting point.  I'll also assume that we have
$100,000,000 in reserve for the downturn.  That's probably a bit high.

It's spreadsheet time!  I'll create mine, you can create your own.

In mine, I find that in year 20, the expected contribution from the
endowment exceeds the money available from the payout.  In particular,
I have the endowment at $2,440,380,080, the payout at $97,615,203,
the budget at $180,611,123, and the amount needed at $180,611,123.
Fortunately, by that time the reserve has grown to $826,884,019.  The
joy of compound interest!  If I trust my formulae, and perhaps I should
not, it takes until year 60 for the reserve to run out.

Maybe I need slightly more conservative estimates.  I see from a
recent budget presentation that our expenses have grown by about
5.44% per year.  I suppose the 3% was a bit optimistic.  Let's
assume we are a bit more conservative, and cut it to 5%.  The
starting budget should really be $140,000,000.  Time to find a new
envelope!  More precisely, it's time to update the spreadsheet.  I
should also generalize it, so it's easier to update.

Ouch!  That's much more painful.  The expected contribution from the
endowment exceeds the payout in year one.  And we've overdrawn the
reserves by year 10.  That's scary.  Here's my table.

<table class="table">
 <tr>
  <th>Year</th>
  <th>Endowment</th>
  <th>Interest</th>
  <th>Payout</th>
  <th>Budget</th>
  <th>From Endowment</th>
  <th>To Reserve</th>
  <th>Reserve</th>
 </tr>
 <tr>
  <td align="right">0</td>
  <td align="right">$2,000,000,000</td>
  <td align="right">$100,000,000</td>
  <td align="right">$80,000,000</td>
  <td align="right">$140,000,000</td>
  <td align="right">$77,000,000</td>
  <td align="right">$3,000,000</td>
  <td align="right">$103,000,000</td>
 </tr>
 <tr>
  <td align="right">1</td>
  <td align="right">$2,020,000,000</td>
  <td align="right">$101,000,000</td>
  <td align="right">$80,800,000</td>
  <td align="right">$147,000,000</td>
  <td align="right">$80,850,000</td>
  <td align="right">-$50,000</td>
  <td align="right">$108,100,000</td>
 </tr>
 <tr>
  <td align="right">2</td>
  <td align="right">$2,040,200,000</td>
  <td align="right">$102,010,000</td>
  <td align="right">$81,608,000</td>
  <td align="right">$154,350,000</td>
  <td align="right">$84,892,500</td>
  <td align="right">-$3,284,500</td>
  <td align="right">$110,220,500</td>
 </tr>
 <tr>
  <td align="right">3</td>
  <td align="right">$2,060,602,000</td>
  <td align="right">$103,030,100</td>
  <td align="right">$82,424,080</td>
  <td align="right">$162,067,500</td>
  <td align="right">$89,137,125</td>
  <td align="right">-$6,713,045</td>
  <td align="right">$109,018,480</td>
 </tr>
 <tr>
  <td align="right">4</td>
  <td align="right">$2,081,208,020</td>
  <td align="right">$104,060,401</td>
  <td align="right">$83,248,321</td>
  <td align="right">$170,170,875</td>
  <td align="right">$93,593,981</td>
  <td align="right">-$10,345,660</td>
  <td align="right">$104,123,744</td>
 </tr>
 <tr>
  <td align="right">5</td>
  <td align="right">$2,102,020,100</td>
  <td align="right">$105,101,005</td>
  <td align="right">$84,080,804</td>
  <td align="right">$178,679,419</td>
  <td align="right">$98,273,680</td>
  <td align="right">-$14,192,876</td>
  <td align="right">$95,137,054</td>
 </tr>
 <tr>
  <td align="right">6</td>
  <td align="right">$2,123,040,301</td>
  <td align="right">$106,152,015</td>
  <td align="right">$84,921,612</td>
  <td align="right">$187,613,390</td>
  <td align="right">$103,187,364</td>
  <td align="right">-$18,265,752</td>
  <td align="right">$81,628,155</td>
 </tr>
 <tr>
  <td align="right">7</td>
  <td align="right">$2,144,270,704</td>
  <td align="right">$107,213,535</td>
  <td align="right">$85,770,828</td>
  <td align="right">$196,994,059</td>
  <td align="right">$108,346,733</td>
  <td align="right">-$22,575,904</td>
  <td align="right">$63,133,658</td>
 </tr>
 <tr>
  <td align="right">8</td>
  <td align="right">$2,165,713,411</td>
  <td align="right">$108,285,671</td>
  <td align="right">$86,628,536</td>
  <td align="right">$206,843,762</td>
  <td align="right">$113,764,069</td>
  <td align="right">-$27,135,533</td>
  <td align="right">$39,154,808</td>
 </tr>
 <tr>
  <td align="right">9</td>
  <td align="right">$2,187,370,545</td>
  <td align="right">$109,368,527</td>
  <td align="right">$87,494,822</td>
  <td align="right">$217,185,950</td>
  <td align="right">$119,452,273</td>
  <td align="right">-$31,957,451</td>
  <td align="right">$9,155,098</td>
 </tr>
 <tr>
  <td align="right">10</td>
  <td align="right">$2,209,244,251</td>
  <td align="right">$110,462,213</td>
  <td align="right">$88,369,770</td>
  <td align="right">$228,045,248</td>
  <td align="right">$125,424,886</td>
  <td align="right">-$37,055,116</td>
  <td align="right">-$27,442,263</td>
 </tr>
</table>

How did I compute that?  Here's an approximation of the formulae
in my spreadsheet.

<table class="table">
 <tr>
  <th></th>
  <th>A</th>
  <th>B</th>
  <th>C</th>
  <th>D</th>
  <th>E</th>
  <th>F</th>
  <th>G</th>
  <th>H</th>
 </tr>
 <tr>
  <th>Row</th>
  <th>Year</th>
  <th>Endowment</th>
  <th>Interest</th>
  <th>Payout</th>
  <th>Budget</th>
  <th>From Endowment</th>
  <th>To Reserve</th>
  <th>Reserve</th>
 </tr>
 <tr>
  <td>1</td>
  <td>0</td>
  <td><code>=INIT_ENDOW</code></td>
  <td><code>=B1*INTEREST</code></td>
  <td><code>=B1*PAYOUT</code></td>
  <td><code>=INIT_BUDGET</code></td>
  <td><code>=E1*ENDOW_PERC</code></td>
  <td><code>=C1-F1</code></td>
  <td><code>=INIT_RESERVE+G1</td>
 </tr>
 <tr>
  <td>2</td>
  <td>1</td>
  <td><code>=B1+C1-D1</code></td>
  <td><code>=B2*INTEREST</code></td>
  <td><code>=B2*PAYOUT</code></td>
  <td><code>=E1*(1+BUDG_GROW)</code></td>
  <td><code>=E2*ENDOW_PERC</code></td>
  <td><code>=C2-F2</code></td>
  <td><code>=H1*(1+INTEREST)+G2</td>
 </tr>
</table>

The remaining rows are appropriate variations of row 2.

Now that I have the spreadsheet generalized, I can try other things.
What if we earn 6%?

---

**_Postscript_**: Thanks to Eldest, who I hope will check my work.

---

[1] And for many other things.

[2] Given how I've heard fundraising worked at the College during
that time, it seems that no one thought so.
