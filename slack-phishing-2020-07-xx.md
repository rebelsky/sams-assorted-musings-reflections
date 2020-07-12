---
title: Slack phishing via Webhooks
number: 
tags: 
blurb: Such a fascinating title.
version: 
released: 
current: 
---
Maybe this should be a CS table.

Links

Original Work

https://cybersecurity.att.com/blogs/labs-research/slack-phishing-attacks-using-webhooks

Interview and Transcript

https://thecyberwire.com/podcasts/research-saturday/140/transcript

https://podcasts.apple.com/us/podcast/click-here-to-update-your-webhook/id1071831261?i=1000478769062

Other Notes

https://www.uctoday.com/collaboration/team-collaboration/slack-webhooks-exposed-as-potential-phishing-hooks/

https://www.darkreading.com/cloud/slacks-incoming-webhooks-can-be-weaponized-in-phishing-attacks/d/d-id/1337573

---

Transcript of interview

Dave Bittner: Hello everyone, and welcome to the CyberWire's Research Saturday presented by Juniper Networks. I'm Dave Bittner, and this is our weekly conversation with researchers and analysts tracking down threats and vulnerabilities, solving some of the hard problems of protecting ourselves in a rapidly evolving cyberspace. Thanks for joining us.

Dave Bittner: And now a quick word about our sponsor, Juniper Networks. NSS Labs gave Juniper its highest rating of "Recommended" in its recent Data Center Security Gateway Test. To get your copy of the NSS Labs report, visit juniper.net/securedc, or connect with Juniper on Twitter or Facebook. That's juniper.net/securedc. And we thank Juniper for making it possible to bring you Research Saturday.

Dave Bittner: Thanks to our sponsor, Enveil, whose revolutionary ZeroReveal solution protects data while it's being used or processed – the holy grail of data encryption. Enveil delivers privacy-preserving capabilities to enable critical business functions. Organizations can securely derive insights, cross-match, and search third-party data assets without ever revealing the contents of the interaction or compromising the ownership of the underlying data. What was once only theoretical is now possible with Enveil. Learn more at enveil.com.

Ashley Graves: Slack offers integration with third-party tools using OAuth. You can share different types of data between your Slack workspace and other users.

Dave Bittner: That's Ashley Graves. She's a Cloud Security Researcher at AT&T Alien Labs. The research we're discussing today is titled, "Slack Phishing Attacks Using Webhooks."

Ashley Graves: Webhooks specifically are a type of Slack app that lets you post certain information to a channel. So, given a secret URL, if someone knows that URL, they can send a message to the channel using that.

Dave Bittner: I see. And so, the research that you've done here explores some potential vulnerabilities that come from that functionality.

Ashley Graves: Yeah, I wouldn't categorize it as a vulnerability – I would categorize it more as abuse of a feature.

Dave Bittner: I see. Well, let's walk through it together. Take us through what you've outlined here. How does this functionality work?

Ashley Graves: Sure. So, as I mentioned, there's two features that this uses. There's webhooks and there's a third-party integration via OAuth. So, basically, if users can send these messages to a select channel with the pseudo-secret URL, then they could, in theory, send a phishing message that is used to convince users to grant access to their Slack data using OAuth or that thing that allows third-party integrations.

Dave Bittner: Well, let's walk through this step by step...

Ashley Graves: Sure.

Dave Bittner: ...You lay it out here in the research here. Walk me through the steps here.

Ashley Graves: Yeah, of course. First, on the victim's side, the victim has, say, created a webhook. So, the victim knows the webhook URL. They may accidentally share that URL, whether it's posting it through GitHub or having it in a document that they shared by accident. So, once this webhook is known by an attacker, that attacker can send a message containing a phishing link similar to how you would send a phishing link through email.

Ashley Graves: The unique thing about the second part of it is the third-party app integration. So, instead of sending a link to, say, a phishing site that's asking for your credentials, you would send them the link to your third-party OAuth application. So, this application would be built with the purpose of exfiltrating some data from Slack or somehow interacting with Slack. So, for example, you might want to steal all the user's uploaded documents, you might want to access their chat. So, if a user clicks this link and grants access to the third-party application, that third party then has access to whatever data the application scope's defined.

Dave Bittner: Hmm. Yeah, that's the part that really fascinates me here, because my understanding is that the webhooks functionality is designed to basically have data flow in one direction – only to be used to be able to post things to a Slack channel. Is that correct?

Ashley Graves: Yes, that's correct.

Dave Bittner: And so how do we get from that functionality to the ability to exfiltrate data? It's the creation of this custom app?

Ashley Graves: Yeah. So, the webhook itself – the only purpose of the webhook is to send that information in one direction, to send that malicious link to the victim's Slack workspace specifically. So, once they click the link, from there on out, it is all this third-party OAuth application that is doing the heavy lifting.

Dave Bittner: I see. And so, one thing you outline here is a potential sort of formatting of that message, making it look like it would be something that just in the course of their day, they probably wouldn't think twice about clicking on. How do you have that described here?

Ashley Graves: Yeah. So, in this case, if someone already has a webhook set up, and you have that webhook URL and you send a message to that URL, it'll use the webhook's name as they would normally see it. So, if someone had an incoming webhook – in my example, it's just called "Incoming Webhook" – but so, if you are already familiar with this application being in your channel, you might not think twice if there's an error that says "click here to update your webhook." And maybe the person who owns it will click it – that is, the person who owns the original webhook. Maybe someone else will click it. It doesn't really matter as long as they fall for it.

Dave Bittner: And so, when they click on that, that's when the access tokens are exchanged. Can you sort of shed some light on that part of it? What happens next?

Ashley Graves: Sure. So, the tokens are obtained right that moment. First, the user – well, the potential victim will click on that URL. They will be prompted with an OAuth screen that basically requests a certain amount of access from them. So, it'll say, for example, "incoming webhooks needs to access your basic information." "Incoming webhooks needs to message your private channel data." Something like that. And then the user can either reject that or accept it. If they do accept it, that is when the token exchange happens. The user will be none the wiser. They're sent back to their Slack workspace as normal, not to any phishing page – not to any obvious phishing page anyways. And from there, the token access is available.

Dave Bittner: And one of the things you point out here is that that page that they're sent to, by all accounts, I mean, it looks like it comes directly from Slack.

Ashley Graves: Yes, that's because it is directly from Slack.

Dave Bittner: Yeah. Right. So there's really – there's no indication that anything is amiss here.

Ashley Graves: Right. The only indication that exists would be the person's gut feeling that it doesn't seem right, that this app should not be requesting this level of data.

Dave Bittner: And so, once the bad folks get the access token, I mean, that's the ballgame, right? Then they have access to be able to exfiltrate data?

Ashley Graves: Yes. Once the attacker has access to the access token, they can access that scope of data on behalf of the user until that token no longer works.

Dave Bittner: And the user themselves would have no indication that this data was flowing out of their Slack instance, for example.

Ashley Graves: That's correct.

Dave Bittner: Wow. Well, let's talk about some of the mitigations here. I mean, for folks who are using Slack, and that's a lot of people, how can they protect themselves against this?

Ashley Graves: Well, there's kind of two sides of the coin here. Slack administrators need to take certain actions if they want to prevent this, and then end users need to have some responsibility or, well, some awareness around what type of risks are associated with Slack or at least third-party applications.

Ashley Graves: On the administrator side, Slack offers something called application whitelisting. So, users would not be able to add a new third-party app until an administrator is able to approve that. And when the administrators get those requests, they will see the application name, some data around it, and what scopes of access the application is requesting.

Dave Bittner: I see. And then on the user side, in terms of awareness, as you said, you know, that sense that something might not be quite right. What sort of tips do you have for them?

Ashley Graves: Yeah, for them there's two things. Improved awareness around secrets handling. So, I think some people legitimately don't understand how much access an attacker can gain when credentials are leaked, and even more so when a webhook secret is leaked. Because people – since this is a one-way communication, they don't see it as sensitive as, say, your AD credentials would be. On the other side of it is understanding what you're giving third parties access to. So, knowing to read those OAuth scopes, understanding how the application that you're using might use that access. Like, it wouldn't make sense – to me, at least – for a webhook to need access to my documents. So, that's something that they have to look over and have some sort of understanding around whether it's some self-learning, whether it's included in security awareness training or something like that.

Dave Bittner: Yeah, it really seems to me like this is one of those examples where you have that tension between the need for security, but also, you know, folks just want to get their work done. And there's that impulse when something like this pops up and it says, hey, I need your permission to access this, that, or the other – I guess there's a lot of people out there who would just say, well, I've got stuff to do, yes, yes, yes. And they just click through.

Ashley Graves: Yeah, absolutely. And I think you see similar things when it comes to the Cambridge Analytica issues with Facebook, the Google Docs phishing attack that happened in the past, where – there were some other issues with Cambridge Analytica, of course, but there were a lot of people saying, oh, I never authorized that app, I never authorized that access, when realistically they did have to go through an OAuth prompt. They did have to allow access to their basic information using that app. And some of it is just clarity issues on the application side. Like, maybe those companies could have done a better job of making it really obvious what kind of data you're handing over. But, of course, at the end of the day, if you want these automation tools and these accessibility tools to work and integrate with your cloud platforms, you need to understand how they're interacting and what you're giving away.

Dave Bittner: Yeah. Now, you have heard from Slack, they responded to your research. What was their reaction?

Ashley Graves: Yeah, so, they responded positively. They repeated most of the recommendations that we offer in the article, which is that you should look for exposed webhooks and invalidate them, that Slack themselves proactively scrapes GitHub, so that if they find webhooks there, they themselves will invalidate them. And also that Slack admins should do due diligence as far as whitelisting.

Dave Bittner: Do you find their response adequate? I mean, is it a satisfying response? Do you feel as though Slack is stepping up here and doing what they can?

Ashley Graves: I'm happy with the response and I appreciate that they allowed us to put out this research. I think that every company, including Slack, can still do better when it comes to explaining these issues. I highlighted a number of things that Slack did not directly respond to, such as the ways that they could possibly improve this interaction. And again, this is something that a user has to fall for. The user has to take some sort of action. And I think that makes people think that an issue is less severe.

Ashley Graves: But again, we've seen in similar attacks in the past that users can be easily tricked and that it's not stupidity. It's not even ignorance. It's just that this is very new technology to a lot of people, and the prompts are not always clear, and there is a lot of small text about how they work. So I think that companies need to, I suppose, make as much effort as possible to help people understand the impact of their actions.

Ashley Graves: I think it's important to mitigate the scope of potential abuse. So, in this example, webhooks being single-channel only could help mitigate the potential damage done if someone does get access to a working webhook. Improving clarity around secrets handling and how important a secret is. And limiting access that unverified apps can have, such as scope or user limitations. So, for example, after the Google Docs phishing attack, Google limited the number of users who could access a certain app if that app wasn't verified or trusted or went through validation in some way. So, they also redid a lot of their OAuth prompts so the clarity improved. So, those type of things are something that only the vendor can do.

Dave Bittner: Our thanks to Ashley Graves from AT&T Alien Labs for joining us. The research is titled, "Slack Phishing Attacks Using Webhooks." We'll have a link in the show notes.

Dave Bittner: Thanks to Juniper Networks for sponsoring our show. You can learn more at juniper.net/security, or connect with them on Twitter or Facebook.

Dave Bittner: And thanks to Enveil for their sponsorship. You can find out how they're closing the last gap in data security at enveil.com.

Dave Bittner: The CyberWire Research Saturday is proudly produced in Maryland out of the startup studios of DataTribe, where they're co-building the next generation of cybersecurity teams and technologies. Our amazing CyberWire team working from home is Elliott Peltzman, Puru Prakash, Stefan Vaziri, Kelsea Bond, Tim Nodar, Joe Carrigan, Carole Theriault, Ben Yelin, Nick Veliky, Gina Johnson, Bennett Moe, Chris Russell, John Petrik, Jennifer Eiben, Rick Howard, Peter Kilpe, and I'm Dave Bittner. Thanks for listening.


