require (ggplot2)

## compile filenames
algorithms <- c("algo1", "algo2", "algo3", "algo4", "algo5", "algo6", "algo7")
filenames <- paste ("~/Documents/algorithm-exercises/exercises/measurements/"
     , paste (algorithms)
     , sep=""
)
filenames.Times <- paste (filenames, "time", sep="-")
filenames.Cycles <- paste (filenames, "cycles", sep="-")

algorithmsNames <- c("formula", "lin. mem & time", "const. mem & lin. time", "exp. by squ.", "eigenval.", "LUT", "exp. by squ. (ite.)")

## extract data to plot (times)
x.space <- 0:93

mean <- vector()
max <- vector()
min <- vector()

for (file in filenames.Times) {
  tmp <- read.table (file, header=F, comment.char="", skip=1) 
  mean <- c(mean, c(tmp[, 5], rep (0, 94 - nrow (tmp))))
  min <- c(min, c(tmp[, 3], rep (0, 94 - nrow (tmp))))
  max <- c(max, c(tmp[, 4], rep (0, 94 - nrow (tmp))))
}
cbPalette <- c("#000000", "#E69F00", "#56B4E9", "#009E73", "#F0E442", "#0072B2", "#D55E00", "#CC79A7")

df <- data.frame (cbind (rep(x.space, 7), min, max, mean))
df[, 5] <- gl (7, 94, 7*94, labels=algorithmsNames)
colnames (df) <- c("n", "min", "max", "mean", "algorithm")

# pdf ("~/Documents/algorithm-exercises/exercises/measurements/plot-time.pdf")

ggplot (df, aes (x=n, y=mean)) +
  ylim(0, 3) + xlab ("n") + ylab ("times (us)") +
  geom_line (aes (group=algorithm, color=algorithm)) +
  geom_ribbon (aes (ymin=min, ymax=max, color=algorithm, fill=algorithm), alpha=0.5) +
  scale_color_manual(values=cbPalette) + 
  scale_fill_manual(values=cbPalette)

ggsave ("~/Documents/algorithm-exercises/exercises/measurements/plot-time.pdf", width=8, height=4)  
  
# dev.off()  

## extract data to plot (times)
x.space <- 0:93

mean <- vector()
max <- vector()
min <- vector()

for (file in filenames.Cycles) {
  tmp <- read.table (file, header=F, comment.char="", skip=1) 
  mean <- c(mean, c(tmp[, 5], rep (0, 94 - nrow (tmp))))
  min <- c(min, c(tmp[, 3], rep (0, 94 - nrow (tmp))))
  max <- c(max, c(tmp[, 4], rep (0, 94 - nrow (tmp))))
}
cbPalette <- c("#000000", "#E69F00", "#56B4E9", "#009E73", "#F0E442", "#0072B2", "#D55E00", "#CC79A7")

df <- data.frame (cbind (rep(x.space, 7), min, max, mean))
df[, 5] <- gl (7, 94, 7*94, labels=algorithmsNames)
colnames (df) <- c("n", "min", "max", "mean", "algorithm")

ggplot (df, aes (x=n, y=mean)) +
  ylim(0, 6000) + xlab ("n") + ylab ("cylces (#)") +
  geom_line (aes (group=algorithm, color=algorithm)) +
  geom_ribbon (aes (ymin=min, ymax=max, color=algorithm, fill=algorithm), alpha=0.5) +
  scale_color_manual(values=cbPalette) + 
  scale_fill_manual(values=cbPalette)  
  
ggsave ("~/Documents/algorithm-exercises/exercises/measurements/plot-cycles.pdf", width=8, height=4)    
  