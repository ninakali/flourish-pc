import sys
from mistletoe import markdown, base_renderer, block_token

class TxtRenderer(base_renderer.BaseRenderer):
    MAXLEN = 48
    listblocks = 0

    def render_heading(self, token):
        if token.level == 1:
            template = '=== {} '
            ready = template.format(self.render_inner(token))
            ready = '\n' + ready + '=' * (self.MAXLEN - len(ready)) + "\n"
            ready = '\n' + '=' * self.MAXLEN + ready + '=' * self.MAXLEN + '\n'
        elif token.level == 2:
            template = '*** {} '
            ready = template.format(self.render_inner(token))
            ready = '\n\n' + ready + "*" * (self.MAXLEN - len(ready)) + "\n\n"
        else:
            template = '\n\n! {}\n'
            ready = template.format(self.render_inner(token))
            ready = ready + "~" * (len(ready)-2) + "\n\n"
        return ready

    def render_strong(self, token):
        template = '*{}*'
        return template.format(self.render_inner(token))

    def render_emphasis(self, token):
        template = '_{}_'
        return template.format(self.render_inner(token))

    def render_list_item(self, token):
        template = ' - {}'
        inner = self.render_inner(token)
        return template.format(inner)


    def render_link(self, token):
        template = '[ {inner} ] =>{target}<='
        if token.target.endswith('.md'):
            target = token.target[:-3] + ".txt"
        else:
            target = token.target  # YOLO
        inner = self.render_inner(token)
        return template.format(target=target, inner=inner)

    def cute_split(self, line):
        cute = []
        tmp = []
        for ch in line:
            if (len(tmp) + self.listblocks*2) < self.MAXLEN :
                tmp.append(ch)
            else:
                idx = len(tmp) - tmp[::-1].index(" ") - 1
                if idx > 1:
                    cute.append(''.join(tmp[:idx]))
                    tmp = tmp[idx+1:]
                    tmp.append(ch)
                else:
                    # shikatanai yo
                    cute.append(''.join(tmp))
                    tmp = [ch]
        cute.append(''.join(tmp))
        return cute


    def render_inner(self, token):
        if isinstance(token, block_token.List):
            self.listblocks += 1
        rendered = [self.render(child) for child in token.children]
        if isinstance(token, block_token.List):
            self.listblocks -= 1
        return ''.join(rendered)

    def render_paragraph(self, token):
        if self.listblocks > 0:
            offset = ""
        else:
            offset = "  "
        inner = (offset + self.render_inner(token)).splitlines()
        new_inner = []
        for line in inner:
            if len(line) > self.MAXLEN:
                for subline in self.cute_split(line):
                    new_inner.append(subline)
            else:
                new_inner.append(line)
        return '{}'.format('\n'.join(new_inner)) + self._block_eol()

    def _block_eol(self):
        return '\n' if self.listblocks > 0 else '\n\n'

with open(sys.argv[1], 'r', encoding='utf-8') if len(sys.argv) == 2 else sys.stdin as infile:
     rendered = markdown(infile, TxtRenderer)
     print(rendered)
