FROM fedora

RUN dnf copr enable -y petersen/haskell-language-server

RUN dnf install -y ShellCheck agda* aspell atool bash-completion bat bzip2 cabal-install cargo catch catch2-devel cflow clang clang-tools-extra clippy clojure cmake codeblocks cppcheck cscope diffutils doctest doxygen doxygen-doxywizard eza file fish gcc gcc-c++ gcovr gdb ghc ghc-Agda ghc-QuickCheck* ghc-aeson* ghc-base-devel ghc-base-doc ghc-base-prelude-doc ghc-cabal-doctest* ghc-crypton-* ghc-doctest* ghc-entropy* ghc-hlint ghc-idris ghc-json* ghc-markdown-unlit ghc-prof ghc-quickcheck* ghc-toml* ghc-yaml* git git-clang-format git-delta glibc-devel.i686 gnupg2 gpgme gpgme-devel graphviz grep haskell-language-server helix highlight hlint hostname htop httpd iproute iputils java-latest-openjdk java-latest-openjdk-devel jq jupyterlab kakoune kcachegrind libasan llvm ltrace lua lua-devel lua-filesystem lua-lpeg luajit lynx make mathjax mc meld micro mkpasswd monkeytype mtr nano nasm nc ncurses neovim nmap nu octave octave-doctest openjfx openssh-server openssl openssl-devel ormolu p7zip pandoc pdflatex perl poetry python-jupytext-doc python3-GitPython python3-Levenshtein python3-black python3-devel python3-docopt python3-flask python3-gitlab python3-gpg python3-ipython python3-jedi python3-jupyter-core python3-jupyterlab python3-jupyterlab-jupytext python3-jupytext python3-matplotlib python3-mypy python3-numpy python3-pandas python3-pip python3-poetry python3-pudb python3-pyflakes python3-pygments python3-pytest python3-requests python3-scapy python3-scikit* python3-scipy python3-seaborn python3-setuptools python3-spyder python3-toml python3-types-requests qemu-* qtcreator ranger ripgrep rr rust rust-debugger-common rust-doc rust-gdb rust-lldb rust-src rustfmt rustup sbcl sed shfmt stack strace tmux traceroute tre valgrind vim-X11 vim-enhanced vim-filesystem vim-fugitive vim-jedi vis wc wget whois xclip xsel yasm yq zsh --skip-unavailable && dnf clean all

RUN pip3 install --no-cache-dir --upgrade automata-lib ete3 mediapy pandas-stubs polars py2cfg qiime-default-reference scikit-bio valgreen # mujoco

RUN wget https://raw.githubusercontent.com/cyrus-and/gdb-dashboard/master/.gdbinit -O ~/.gdbinit
RUN sed -i '1s/^/set disassembly-flavor intel\n/' ~/.gdbinit

RUN mkdir -p ~/bin/ ~/.local/bin/ ~/.cargo/bin/  ~/.config/fish/

RUN echo "fish_vi_key_bindings" >~/.config/fish/config.fish
RUN echo 'fish_config theme choose "ayu Mirage"' >>~/.config/fish/config.fish
# RUN echo "fish_add_path --prepend ~/bin/ ~/.local/bin/ ~/.cargo/bin/" >>~/.config/fish/config.fish
RUN usermod --shell /usr/bin/fish root

# RUN echo "PATH=$HOME/bin/:$HOME/.local/bin/:$HOME/.cargo/bin/:$PATH" >>~/.bash_profile
# RUN echo "export PATH" >>~/.bash_profile

RUN wget https://raw.githubusercontent.com/technomancy/leiningen/stable/bin/lein -O ~/bin/lein
RUN chmod +x ~/bin/lein
RUN ~/bin/lein

RUN echo ":set stop :list" >~/.ghci

RUN cabal update
RUN git clone https://github.com/kowainik/stan.git
RUN cd stan && cabal v2-build exe:stan && cp "$(cabal v2-exec --verbose=0 --offline sh -- -c 'command -v stan')" ~/.local/bin/stan

ENV PATH="/root/bin/:/root/.local/bin/:/root/.cargo/bin/:$PATH"
# Fedora's .bash_profile adds /root/bin/ and /root/.local/bin redundantly, for bash only,
# because apparently, it can't see this at the time of boot?
