# Developer notes

## structure of the project

The __src__ directory is for the framework: documentation in Markdown format, schematics and code in source and target formats (for instance, kicad+png).

The __tools__ directory is for tools needed to convert the sources of the framework into release formats. We strive to make this framework maximally portable by providing plain-text (7-bit ASCII) and print-at-home versions.

The __blobs__ directory is for files used in the repo.

Finally, __beyond__ is for storing files that can be useful for Beyond Flourish.

## Planned release formats

Modern computer screens are excellent; modern computers are crazy fast. But many people don't have access to them. And if we're unlucky, things will get even worse. Using modern computers to develop Flourish PC helps us speed up the process. But we think it is crucial to support most personal computing devices out there, including machines with VERY low memory and resolutions. A "minimal requirements" line shall be drawn, nevertheless.

## HTML release
* The release for users of modern-ish computers
* Optimised for slow computers and poor network connections
* Should use a minimum of HTML and CSS. If it works in IE3, then it's a win
* Should use gif where possible, jpg where feasible

## PDF release
* Intended for print-at-home usage
* A5-formatted PDF document should be comfortable enough to print or read from the screen

## Minimal release

* Text stored as plain text files with up to 40 columns, 7-bit ANSI-compatible encoding
* CR LF as the end of the line (works on DOS, CP/M, Unix, readable on classic Mac)
* Up to 16kB per single file (might be too beefy for smaller machines)
* Images stored as P4 PBM, resolution up to 256x192 pixels for better portability
* Please use pseudo-graphics when possible

### Why 40 columns?

According to a [Wikipedia article](https://en.wikipedia.org/wiki/List_of_home_computers_by_video_hardware), the majority of home computers should be able to display at least 40 characters per line (even if that requires writing some code for software rendering of the fonts). The most significant exception to this rule is pocket computers and early home machines.

The most popular machines can display 40-64 symbols per line with some software hacks.

Here is a mock-up of the default 22-line display mode of VIC-20. It doesn't seem quite readable.
![(VIC-20 trying its best to display a bit of Flourish GitHub page)](https://github.com/ninakali/flourish-pc/blob/main/blobs/cbm.jpg)

On the other hand, even TV-based displays like CGA, with 40-column mode, make a quite readable medium.
![(CGA adapter - mock)](https://github.com/ninakali/flourish-pc/blob/main/blobs/cga.jpg)

### The heck is PBM?
It's a straightforward image format. It goes like this: P4, then the image's resolution as two numbers in ASCII, and then 1bpp bitmap. It takes only 6201 bytes to store a 256x192 image in this format. The resolution is nothing to write home about, but it's useable. Check [parrot.pbm](blobs/parrot.pbm) and its mock fullscreen render:
![(PBM parrot)](https://github.com/ninakali/flourish-pc/blob/main/blobs/parrot.jpg)

This likely would mean that images for minimal release must be manually adjusted or split into multiple parts.
